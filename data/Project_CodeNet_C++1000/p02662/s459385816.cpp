#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int md = 998244353;
  vector<vector<int>> dp(n + 1, vector<int>(s + 1));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      if (j + a[i] <= s) {
        (dp[i + 1][j + a[i]] += dp[i][j]) %= md;
      }
      (dp[i + 1][j] += (dp[i][j] << 1) % md) %= md;
    }
  }
  cout << dp[n][s] << '\n';
  return 0;
}
