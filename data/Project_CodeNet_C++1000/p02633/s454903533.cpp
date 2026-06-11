#include <bits/stdc++.h>
using namespace std;

long long GCD(long long x, long long y) {
  if (y == 0) return x;
  else return GCD(y, x % y);
}

int main() {
  long long X;
  cin >> X;
  cout << 360 / GCD(X, 360) << endl;
}