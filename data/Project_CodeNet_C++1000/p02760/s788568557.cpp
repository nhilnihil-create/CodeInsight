#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

bool vertical(vector<vector<int>> &board){
  bool flg;

  for (int i = 0; i < 3; i++){
    flg = true;
    for (int j = 0; j < 3; j++){
      if (board.at(i).at(j) != 0) flg = false;
    }
    if (flg){
      return true;
    }
  }
  return false;
}

bool horizontal(vector<vector<int>> &board){
  bool flg;

  for (int i = 0; i < 3; i++){
    flg = true;
    for (int j = 0; j < 3; j++){
      if (board.at(j).at(i) != 0) flg = false;
    }
    if (flg){
      return true;
    }
  }
  return false;
}

bool diagonal(vector<vector<int>> &board){
  if ((board.at(0).at(0) ==  0 && board.at(1).at(1) == 0 && board.at(2).at(2) == 0) 
  || (board.at(2).at(0) == 0 && board.at(1).at(1) == 0 && board.at(0).at(2) == 0)){
    return true;
  }
  else
  {
    return false;
  }
  
}

int main(){
  vector<vector<int>> board(3, vector<int>(3));

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> board.at(i).at(j);
    }
  }

  int N;
  cin >> N;
  vector<int> vec(N);

  for (int i = 0; i < N; i++) cin >> vec.at(i);

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if ( find(vec.begin(), vec.end(),board.at(i).at(j)) != vec.end()){
        board.at(i).at(j) = 0;
      }
    }
  }

  if(vertical(board) || horizontal(board) || diagonal(board)){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}