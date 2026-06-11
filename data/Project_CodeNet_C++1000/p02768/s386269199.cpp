#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

int64_t modpow(int64_t x, int64_t n) {
  x = x % MOD;
  if (n == 0)
    return 1;  //再帰の終了条件

  else if (n % 2 == 1) {
    return (x * modpow(x, n - 1)) % MOD;  // nが奇数ならnを1ずらす
  } else
    return modpow((x * x) % MOD, n / 2) % MOD;  // nが偶数ならnが半分になる
}

int64_t comb(int64_t n, int64_t k) {
  int64_t x = 1;
  for (int i = n - k + 1; i <= n; i++) {
    x = x * i % MOD;
  }

  int64_t y = 1;
  for (int i = 1; i <= k; i++) {
    y = y * i % MOD;
  }
  y = modpow(y, MOD - 2);

  return x * y % MOD;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int all = modpow(2, n) - 1;
  int muri = comb(n, a) + comb(n, b);

  int ans = all - muri;
  while (ans < 0) {
    ans += MOD;
  }

  cout << ans << endl;

  return 0;
}