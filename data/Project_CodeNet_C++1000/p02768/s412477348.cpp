#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

long com(long n, long r) {
  if (n < r || n < 0 || r < 0) return 0;
  long x = 1, y = 1;
  for (int i = 1; i <= r; i++) {
    x = x * (n - i + 1) % MOD;
    y = y * i % MOD;
  }
  return x * mpow(y, MOD - 2) % MOD;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  long ans = mpow(2, n);
  ans -= 1;
  ans -= com(n, a);
  ans -= com(n, b);
  while (ans < 0) ans += MOD;
  cout << ans << "\n";
}