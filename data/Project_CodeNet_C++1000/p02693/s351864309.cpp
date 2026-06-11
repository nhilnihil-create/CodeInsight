#include <bits/stdc++.h>
using namespace std;
int main() {
  bool b = false;
  int K, A, B;
  cin >> K >> A >> B;
  int C = A;
  for (int i = 0; i < B - A + 1; i++) {
    if (C % K == 0) {
      b = true;
      break;
    }
    C++;
  }
  if (b) {cout << "OK" << endl;}
  else {cout << "NG" << endl;}
}