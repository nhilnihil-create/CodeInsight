#include <bits/stdc++.h>
using namespace std;

constexpr long MOD = 1000000007;

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return res;
}

long com(long n, long r) {
  long x = 1, y = 1;
  for (int i = 1; i <= r; i++) {
    x = x * (n - i + 1) % MOD;
    y = y * i % MOD;
  }
  return x * mpow(y, MOD - 2) % MOD;
}

int main() {
  int X, Y;
  cin >> X >> Y;
  if ((X + Y) % 3) return cout << 0 << "\n", 0;
  int n = (X + Y) / 3;
  int r = Y - n;
  if (r < 0) return cout << 0 << "\n", 0;
  cout << com(n, r) << "\n";
}