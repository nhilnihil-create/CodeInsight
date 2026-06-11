#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int INF = 1e9;

signed main() {
  string s;
  cin >> s;

  s = '0' + s;
  int n = (int)s.size();

  vector<vector<int>> dp(n + 1, vector<int> (2, INF));

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int current = s[i] - '0';
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + current);
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (10 - current));
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + current + 1);
    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (9 - current));
  }
  cout << dp[n][0] << '\n';
}
