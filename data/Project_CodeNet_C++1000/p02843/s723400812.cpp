#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X;
  Y = X % 100;
  Z = X / 100;
  if (Z >= (Y + 4) / 5) cout << 1 << endl;
  else cout << 0 << endl;
}
