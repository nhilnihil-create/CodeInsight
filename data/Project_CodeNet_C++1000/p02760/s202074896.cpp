#include <bits/stdc++.h>
using namespace std;
 
int main () {
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
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (A.at(i).at(j) == b.at(k)) {
          A.at(i).at(j) = 0;
        }
      }
    }
  }
  int ans = 0;
  bool ok = false;
  for (int i = 0; i < 3; i++) {
    if (0 == A.at(i).at(0) && 0 == A.at(i).at(1) && 0 == A.at(i).at(2)) {
      ok = true;
      break;
    }
    if (0 == A.at(0).at(i) && 0 == A.at(1).at(i) && 0 == A.at(2).at(i)) {
      ok = true;
      break;
    }
  }
  if (0 == A.at(0).at(0) && 0 == A.at(1).at(1) && 0 == A.at(2).at(2)) {
    ok = true;
  }
  if (0 == A.at(0).at(2) && 0 == A.at(1).at(1) && 0 == A.at(2).at(0)) {
    ok = true;
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}