#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

int main() {
  int n, s; cin >> n >> s;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  vector<vector<ll>> dp(n+1, vector<ll>(s+1));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      dp[i+1][j] += 2*dp[i][j];
      dp[i+1][j] %= mod;
      if (j+a.at(i) <= s) {
        dp[i+1][j+a.at(i)] += dp[i][j];
        dp[i+1][j+a.at(i)] %= mod;
      }
    }
  }
  cout << dp[n][s] << '\n';
  return 0;
}
