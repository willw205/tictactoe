/*
  Name: William Wong
  Date: 10-13-022
  Project: A two player tictactoe game against humans
  not against an AI. This game will detect if either X Wins
  or O Wins. And will also detect ties within the game.

*/


#include <iostream>
#include <cstring>
using namespace std;

//Below we are initializing the variables

void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
void rebootGame(char board[3][3], bool&  tictacAddict);
bool checkWin(char board[3][3], int player);
bool checkTie(char board[3][3], int player);


int main() {

  char X_MOVE = 'X';
  char O_MOVE = 'O';
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int x_Wins = 0;
  int o_Wins = 0;
  int ties = 0;
  bool tictacAddict = true;
  char board[3][3];
  char str[3];

  clearBoard(board);
  
  while (tictacAddict == true) {

    //After game restarts. It is always X's turn.
    
    turn = X_TURN;

   while (checkWin(board, X_MOVE) == false && checkWin(board, O_MOVE) == false &&
	   checkTie(board, X_MOVE) == false && checkTie(board, O_MOVE) == false) {
      if (turn == X_TURN) {
	cout << "It's X's Move!" << endl;
      }
      else {
	cout << "It's O's Move!!" << endl;
      }
      
      printBoard(board);

      cin.get(str,3);
      cin.get();

      // Checks if user input is a valid input 

        if (strlen(str) != 2) {
	cout << "Not Valid! Enter Again." << endl;
      }
      else if (str[0] != 'a' && str[0] != 'b' && str[0] != 'c') {
	cout << "Not Valid! Enter Again." << endl;
      }
      else if (str[1] != '1' && str[1] != '2' && str[1] != '3') {
	cout << "Not Valid! Enter Again." << endl;
      }
	
      // If the input is valid it is inserted into the board
	
      else {
	int column = str[0] - 'a';
	int row = str[1] - '1';
	if (board[row][column] == ' ') {
	  if (turn == X_TURN) { 
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  }
	  else { 
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	}
	// Helps to print if the position on board is already taken
	else { 
	  cout << "Location is already taken!" << endl;
	}
      }
    }
   
    // When Player X Wins

   if (checkWin(board, X_MOVE) == true) {
      x_Wins++;
      cout << " " << endl;
      cout << "X Has Won!" << endl;
      cout << "X Wins: " << x_Wins << endl;
      cout << "O Wins: " << o_Wins << endl;
      cout << "Ties: " << ties << endl; 
      rebootGame(board, tictacAddict);
    
    }
    
    // When Player O Wins
   
    else if (checkWin(board, O_MOVE) == true) {
      o_Wins++;
      printBoard(board);
      cout << " " << endl;
      cout << "O Has Won!" << endl;
      cout << "X Wins: " << x_Wins << endl;
      cout << "O Wins: " << o_Wins << endl;
      cout << "Ties: " << ties << endl; 
      rebootGame(board, tictacAddict);
    }
    
    // When there is a tie
    
    else if (checkTie(board, O_MOVE) == true) {
      printBoard(board);
      ties++;
      cout << " " << endl;
      cout << "It's A Tie" << endl;
      cout << "X Wins: " << x_Wins << endl;
      cout << "O Wins: " << o_Wins << endl;
      cout << "Ties: " << ties << endl; 
      rebootGame(board, tictacAddict);
    }
    
   // When there is a tie 
    
    else if (checkTie(board, X_MOVE) == true) {
      printBoard(board);
      ties++;
      cout << " " << endl;
      cout << "It's A Tie" << endl;
      cout << "X Wins: " << x_Wins << endl;
      cout << "O Wins: " << o_Wins << endl;
      cout << "Ties: " << ties << endl;
      rebootGame(board, tictacAddict);
    }
  }
}

void printBoard(char board[3][3]) {

  cout << " " << endl;
  cout << "\t        Tic Tac Toe Game"<< endl;

  cout << "\t Player 1 (X) || Player 2 (O)" << endl;
  cout << " " << endl;
  cout << "\t\t    1 2 3" << endl;
  cout << "\t\t  a " << board[0][0] << ' ' << board[1][0] << ' ' << board[2][0] << endl;
  cout << "\t\t  b " << board[0][1] << ' ' << board[1][1] << ' ' << board[2][1] << endl;
  cout << "\t\t  c " << board[0][2] << ' ' << board[1][2] << ' ' << board[2][2] << endl;    
  
}

void clearBoard(char board[3][3]) {

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
    
  }
  
}

bool checkWin(char board[3][3], int player) {

  // Below helps to check both vertical and horizontal wins
  
  for (int a = 0; a < 3; a++) {
    if (board[a][0] == player && board[a][1] == player && board[a][2] == player) {
      return true;
    }
    if (board[0][a] == player && board[1][a] == player && board[2][a] == player) {
      return true;
    }
  }
  
  // Helps to check the diaganol wins. Totally spelled diaganol right. Notsure...
  
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
  
}

//Helps to check if there are any ties 

bool checkTie(char board[3][3], int player) {

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {

      if(board[i][j] == ' ') {
	return false;
      }
      
    }
    
  }
  return true;
  
}

// This function is used to restart the game

void rebootGame(char board[3][3], bool& tictacAddict) {

  char playAgain;

  cout << "Do you want to play again? (y or n): " << endl;
  cin.get(playAgain);
  cin.get();

  if(playAgain == 'y') {
    clearBoard(board);
  } else {
    cout << "Thank you for tic tacking on! See you around! And download Bettervue!" << endl;
    tictacAddict = false;
  }

}
