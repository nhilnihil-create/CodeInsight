#include <bits/stdc++.h>
using namespace std;

int main () {
  /*
  vector<int> data(3);
  for (int i = 0; i < 3; i++) {
    cin >> data.at(i);
  }

  int count = 0;
  for (int x : data) {
    if (data.at(0) == x) {
      count ++;
    }
    if (data.at(1) == x) {
      count ++;
    }
    if (data.at(2) == x) {
      count ++;
    }
  }
  if (count == 3) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  */
  int A, B, C;
  cin >> A >> B >> C;

  if (A == B) {
    if (A != C) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else if (B == C) {
    if (B != A) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else if (C == A) {
    if (C != B) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}
