#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;

int main(){ 
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i];

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  dp[0][0] = 1;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 && j == 0) continue;
      if (i == 0) {
        dp[i][j] = dp[i][j - 1];
        continue;
      }
      if (j == 0) {
        dp[i][j] = dp[i - 1][j];
        continue;
      }
      (dp[i][j] += dp[i - 1][j]) %= mod;
      (dp[i][j] += dp[i][j - 1]) %= mod;
      ((dp[i][j] -= dp[i - 1][j - 1]) += mod) %= mod;
      if (s[i - 1] == t[j - 1]) (dp[i][j] += dp[i - 1][j - 1]) %= mod;
    }
  }
  cout << dp[n][m] << endl;
  return 0; 
} 
