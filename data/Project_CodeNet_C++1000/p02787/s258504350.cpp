#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000000202;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  int a_max = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a_max = max(a_max, a[i]);
  }
  vector<int> dp(20010, INF);
  dp[0] = 0;
  for (int i = 1; i <= h + a_max; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j] <= i) {
        dp[i] = min(dp[i], dp[i - a[j]] + b[j]);
      } else {
        dp[i] = min(dp[i], b[j]);
      }
    }
  }
  int ans = INF;
  for (int i = h; i <= h + a_max; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}