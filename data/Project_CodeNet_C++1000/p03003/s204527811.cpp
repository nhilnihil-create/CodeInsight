#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int mod = 1e9 + 7;

ll dp[2020][2020];
ll sum[2020][2020];

int main() {
  int n,m;
  cin >> n >> m;

  vector<int> s(n), t(m);
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i];

  memset(dp,0,sizeof(dp));
  memset(sum,0,sizeof(sum));

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(s[i] == t[j]) {
        dp[i + 1][j + 1] = sum[i][j] + 1;
        dp[i + 1][j + 1] %= mod;
      } else {
        dp[i + 1][j + 1] = 0;
      }
      sum[i + 1][j + 1] = (sum[i + 1][j] + sum[i][j + 1] + dp[i + 1][j + 1] + mod - sum[i][j]) % mod;
    }
  }
  ll answer = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      answer += dp[i][j];
      answer %= mod;
    }
  }
  cout << answer << '\n';
}
