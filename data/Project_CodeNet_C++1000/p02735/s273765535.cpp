#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) {
    cin >> a[i];
  }
  const int mx = 205;
  vector<vector<int>> dp(h, vector<int>(w, mx));
  rep(i, h) {
    rep(j, w) {
      if (i == 0 && j == 0) dp[0][0] = (a[0][0] == '#');
      if (i > 0)
        dp[i][j] = min(dp[i][j],
                       dp[i - 1][j] + (a[i - 1][j] == '.' && a[i][j] == '#'));
      if (j > 0)
        dp[i][j] = min(dp[i][j],
                       dp[i][j - 1] + (a[i][j - 1] == '.' && a[i][j] == '#'));
    }
  }
  cout << dp[h - 1][w - 1];
  return 0;
}