#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, n;
  cin >> h >> n;
  const int INF = (int)1e9;
  vector<int> dp(h + 1, INF);
  dp[0] = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= h; i++) {
      int j = min(i + a, h);
      dp[j] = min(dp[j], dp[i] + b);
    }
  }
  cout << dp[h];
  return 0;
}