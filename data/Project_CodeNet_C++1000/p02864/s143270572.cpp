#include <bits/stdc++.h>
using namespace std;

const long inf = 1e18;
int n, r;
long a[301];
long dp[302][301];

int main() {
  cin >> n >> r;
  ++n;
  a[0] = 0;
  for (int i = 1; i < n; ++i) cin >> a[i];
  for (int k = 0; k <= n - r; ++k) {
    for (int i = 0; i < n; ++i) {
      dp[k][i] = inf;
    }
  }
  dp[1][0] = 0;
  
  for (int k = 2; k <= n - r; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[k][i] = min(dp[k][i], dp[k - 1][j] + max(0l, a[i] - a[j]));
      }
    }
  }
  
  long mn = inf;
  for (int i = 0; i < n; ++i) {
    mn = min(mn, dp[n - r][i]);
  }
  cout << mn << endl;
}