#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<vector<int>> data(3, vector<int>(3));

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> data.at(i).at(j);
    }
  }

  int N;
  cin >> N;
  
  vector<int> b(N);
  for (int i = 0; i < N; i++)
    cin >> b.at(i);
  
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < N; k++) {
    	if(b.at(k) == data.at(i).at(j))
          data.at(i).at(j) = 0;
      }
    }
  }
  
  bool bingo = false;
  
  for (int i = 0; i < 3; i++) {
    if(data.at(i).at(0) == 0 && data.at(i).at(1) == 0 && data.at(i).at(2) == 0)
      bingo = true;
  }
  for (int i = 0; i < 3; i++) {
    if(data.at(0).at(i) == 0 && data.at(1).at(i) == 0 && data.at(2).at(i) == 0)
      bingo = true;
  }
  if(data.at(0).at(0) == 0 && data.at(1).at(1) == 0 && data.at(2).at(2) == 0)
      bingo = true;
  if(data.at(0).at(2) == 0 && data.at(1).at(1) == 0 && data.at(2).at(0) == 0)
      bingo = true;
  
  if(bingo)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}