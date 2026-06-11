#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<vector<int>> A(3, vector<int>(3));
  bool c = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int N;
  cin >> N;
  for (int h = 0; h < N; h++) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (A.at(i).at(j) == b) {A.at(i).at(j) = 0;}
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (A.at(0).at(i) == 0 && A.at(1).at(i) == 0 && A.at(2).at(i) == 0) {c = true;}
  }
  for (int i = 0; i < 3; i++) {
    if (A.at(i).at(0) == 0 && A.at(i).at(1) == 0 && A.at(i).at(2) == 0) {c = true;}
  }
  if (A.at(0).at(0) == 0 && A.at(1).at(1) == 0 && A.at(2).at(2) == 0) {c = true;}
  else if (A.at(0).at(2) == 0 && A.at(1).at(1) == 0 && A.at(2).at(0) == 0) {c = true;}
  if (c) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}