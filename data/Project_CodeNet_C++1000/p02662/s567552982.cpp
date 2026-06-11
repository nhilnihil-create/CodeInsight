#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 998244353;

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  
  vector<int> a(n+1);
  vector<vector<int>> dp(n + 1, vector<int> (s + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j) {
      if (j >= a[i]) dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]]) % M;
      dp[i][j] = (dp[i][j] + 2 * dp[i-1][j] % M) % M;
    }
  }
  cout << dp[n][s] << '\n'; 
}
