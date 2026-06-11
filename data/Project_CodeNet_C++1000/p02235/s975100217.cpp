#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    string x, y;
    cin >> x >> y;
    int m = x.length();
    int n = y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (x[i - 1] == y[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    int ret = dp[m][n];
    cout << ret << '\n';
  }
  return 0;
}
