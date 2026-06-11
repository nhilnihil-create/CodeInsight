#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll mod = 1000000007;
  int n, m;
  cin >> n >> m;
  vector<int> s(n + 1), t(m + 1);
  rep(i, n)
    cin >> s[i+1];
  rep(i, m)
    cin >> t[i+1];
  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1));
  for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
      if (s[i] == t[j])
        dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
      else
        dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]) % mod;
  if (dp[n][m] < 0)
    dp[n][m] += mod;
  cout << dp[n][m] << endl;
  return 0;
}