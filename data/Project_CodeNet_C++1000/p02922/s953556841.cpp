#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (B==1) {
    cout << 0 << endl;
  }
  else {
    A--;
    B-=2;
    cout << B/A+1 << endl;
  }
}