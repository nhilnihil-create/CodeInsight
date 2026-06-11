#include <bits/stdc++.h>
using namespace std;
int main() {
  int A;
  cin >> A;
  double B = A;
  if(A % 2 == 0) {
    cout << 0.5 << endl;
  }
  else {
    cout << (B + 1) / 2 / B << endl;
  }
}
