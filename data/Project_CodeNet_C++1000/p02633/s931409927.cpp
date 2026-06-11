#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, p = 0;
  cin >> X;
  for (int i = 0; i < 360; i++) {
    p = (p+X)%360;
    if (p == 0) {
      cout << i+1 << endl;
      return 0;
    }
  }
}