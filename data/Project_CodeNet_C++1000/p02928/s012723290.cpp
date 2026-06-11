#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

static ll MOD = 1'000'000'007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  ll res = 0;
  for (int i = 0; i < n; i++) {
    // 転倒数 a内
    // 転倒数 全体
    ll ina = 0;
    ll inTotal = 0;
    for (int j = i + 1; j < n; j++) {
      if (a.at(i) > a.at(j)) {
        ina++;
      }
    }
    for (int j = 0; j < n; j++) {
      if (a.at(i) > a.at(j)) {
        inTotal++;
      }
    }
    res += (ina * k) % MOD;
    res %= MOD;
    res += (inTotal * (((ll) k * (k - 1)) / 2 % MOD)) % MOD;
    res %= MOD;
  }
  cout << res << endl;
  return 0;
}
