#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if(A == B) {
    if(A == C) {
      cout << "No";
    }
    else {
      cout << "Yes";
    }
  }
  else if(A == C) {
    if(B == C) {
      cout << "No";
    }
    else {
      cout << "Yes";
    }
  }
  else if(C == B) {
    if(A == C) {
      cout << "No";
    }
    else {
      cout << "Yes";
    }
  }
  else {
    cout << "No";
  }
}