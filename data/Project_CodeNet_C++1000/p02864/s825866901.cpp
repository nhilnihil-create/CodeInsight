#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll dp[310][310];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 0; k <= i - 1; ++k) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0, h[i] - h[k]));
      }
    }
  }
  ll ans = 1e18;
  for (int i = 0; i <= n; ++i) {
    ans = min(ans, dp[i][n - k]);
  }
  cout << ans << endl;
  return 0;
}