#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> ng(n + 1);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    ng[a] = true;
  }

  const ll mod = 1e9 + 7;
  vector<ll> memo(n + 1, -1);
  memo[0] = 1;
  function<ll(int)> f = [&](int n) -> ll {
    if (n < 0)
      return 0;
    if (memo[n] != -1)
      return memo[n];
    if (ng[n])
      return 0;
    return memo[n] = (f(n - 1) + f(n - 2)) % mod;
  };
  cout << f(n) << endl;

  // vector<ll> dp(n + 1, 0);
  // dp[0] = 1;
  // for (int i = 1; i <= n; i++) {
  //   if (find(a.begin(), a.end(), i) != a.end())
  //     continue;
  //   dp[i] += dp[i - 1];
  //   dp[i] %= mod;
  //   if (i > 1) {
  //     dp[i] += dp[i - 2];
  //     dp[i] %= mod;
  //   }
  // }
  //
  // cout << dp[n] << endl;

  return 0;
}
