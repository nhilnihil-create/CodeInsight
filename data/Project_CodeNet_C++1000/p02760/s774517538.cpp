#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int N;
  cin >> N;
  vector<int> b(N);
  for (int i = 0; i < N; i++) {
    cin >> b.at(i);
  }
  vector<vector<char>> bingo = {{'x','x','x'},{'x','x','x'},{'x','x','x'}};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (b.at(i) == A.at(j).at(k)) {
          bingo.at(j).at(k) = 'o';
        }
      }
    }
  }

  //行の判定
  for (int i = 0; i < 3; i++) {
    if (bingo.at(i).at(0) == 'o' && bingo.at(i).at(1) == 'o' && bingo.at(i).at(2) == 'o') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  //列の判定
  for (int i = 0; i < 3; i++) {
    if (bingo.at(0).at(i) == 'o' && bingo.at(1).at(i) == 'o' && bingo.at(2).at(i) == 'o') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  //斜めの判定
  if (bingo.at(0).at(0) == 'o' && bingo.at(1).at(1) == 'o' && bingo.at(2).at(2) == 'o') {
    cout << "Yes" << endl;
    return 0;
  }
  if (bingo.at(2).at(0) == 'o' && bingo.at(1).at(1) == 'o' && bingo.at(0).at(2) == 'o') {
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
}