#include <iostream>
#include <string>
using namespace std;

int str_length(string);

typedef struct {
  int up;
  int back;
  int right;
  int left;
  int front;
  int down;
}dicetype;

int main(void){

  dicetype dice;
  string order;

  cin >> dice.up >> dice.back >> dice.right >> dice.left >> dice.front >> dice.down;

  cin >> order;

  for ( int i = 0 ; i < str_length(order) ; i++){
    switch(order[i]){

      int temp;

      case 'N':
      temp = dice.up;
      dice.up = dice.back;
      dice.back = dice.down;
      dice.down = dice.front;
      dice.front = temp;
      break;

      case 'S':
      temp = dice.up;
      dice.up = dice.front;
      dice.front = dice.down;
      dice.down = dice.back;
      dice.back = temp;
      break;

      case 'E':
      temp = dice.up;
      dice.up = dice.left;
      dice.left = dice.down;
      dice.down = dice.right;
      dice.right = temp;
      break;

      case 'W':
      temp = dice.up;
      dice.up = dice.right;
      dice.right = dice.down;
      dice.down = dice.left;
      dice.left = temp;
      break;

      default:
      break;
    }
  }

  cout << dice.up << endl;

  return 0;
}



int str_length(string str){
  int strlen;

  strlen = 0;

  while(str[strlen] != '\0'){
    strlen++;
  }

  return strlen;
}