#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int mod = 1e9 + 7;

ll dp[100005];

ll f(int i) {
  if (i < 0) return 0;
  if (dp[i] == -1) return 0;
  if (dp[i] != 0) return dp[i];
  return dp[i] = (f(i - 1) + f(i - 2)) % mod;
}

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a;
    cin >> a;
    dp[a] = -1;
  }
  dp[0] = 1;
  // ll ans = f(n);
  rep(i, n) {
    if (dp[i] == -1) continue;
    if (dp[i + 1] != -1) dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
    if (dp[i + 2] != -1) dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
  }
  cout << dp[n] << endl;
  return 0;
}
