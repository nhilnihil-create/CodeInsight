#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X;
  cin >> A >> B >> C;
  X = A + B + C;
  if(X >= 22) {
    cout << "bust" << endl;
  }
  else {
    cout << "win" << endl;
  }
}