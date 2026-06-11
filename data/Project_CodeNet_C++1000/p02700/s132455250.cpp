#include <bits/stdc++.h>
using namespace std;
int main() {
  bool b = true;
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  while (true) {
    C -= B;
    if (C <= 0) {break;}
    A -= D;
    if (A <= 0) {
      b = false;
      break;
    }
  }
  if (b) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}