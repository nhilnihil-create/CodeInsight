#include <bits/stdc++.h>
using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  int h, n;
  cin >> h >> n;

  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; ++i) {
    int ai, bi;
    cin >> ai >> bi;
    a[i] = ai;
    b[i] = bi;
  }

  int inf = 1e9;
  vector<int> dp(h + 1, inf);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int value = a[i];
    int cost = b[i];
    dp[value] = min(dp[value], cost);
  }

  for (int hi = 0; hi <= h; ++hi) {
    for (int i = 0; i < n; ++i) {
      int value = a[i];
      int cost = b[i];
      // if (value + hi <= h) {
      //   dp[hi + value] = min(dp[hi + value], dp[hi] + cost);
      // }
      // if (value + hi <= h) {
      if (hi - value >= 0) {
        dp[hi] = min(dp[hi], dp[hi - value] + cost);
      } else {
        dp[hi] = min(dp[hi], cost);
      }
    }
  }

  cout << dp[h] << endl;
  // for (int el : dp) {
  //   cout << el << endl;
  // }
  return 0;
}
