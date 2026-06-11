#include<bits/stdc++.h>
using namespace std;
int main() {
  int ibingo[3][3];
  bool bingo[3][3];
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      bingo[i][j] = false;
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> ibingo[i][j];
    }
  }
  int N, b;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> b;
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(b == ibingo[j][k]) bingo[j][k] = true;
      }
    }
  }
  for(int i = 0; i < 3; i++) {
    if(bingo[i][0] == bingo[i][1] && bingo[i][1] == bingo[i][2] && bingo[i][0] == true) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for(int i = 0; i < 3; i++) {
    if(bingo[0][i] == bingo[1][i] && bingo[0][i] == bingo[2][i] && bingo[0][i] == true) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(bingo[0][0] == bingo[1][1] && bingo[1][1] == bingo[2][2] && bingo[0][0] == true) {
    cout << "Yes" << endl;
    return 0;
  }
  if(bingo[0][2] == bingo[1][1] && bingo[1][1] == bingo[2][0] && bingo[0][2] == true) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
//////////////////////////////////////
  /*
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << ibingo[i][j] << " ";
    }
    cout << endl;
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << bingo[i][j] << " ";
    }
    cout << endl;
  } 
  */
}