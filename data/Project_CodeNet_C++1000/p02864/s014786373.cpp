#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int64_t> h(n + 2);
  for (int i = 1; i <= n; i++) cin >> h.at(i);
  vector<vector<vector<int64_t>>> dp(n + 2, vector<vector<int64_t>>(k + 1, vector<int64_t>(n + 2, 1LL << 60)));
  dp.at(0).at(0).at(0) = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= i; l++) {
        dp.at(i).at(j).at(i) = min(dp.at(i).at(j).at(i), dp.at(i - 1).at(j).at(l) + abs(h.at(i) - h.at(l)));
        if (j > 0) {
          dp.at(i).at(j).at(l) = min(dp.at(i).at(j).at(l), dp.at(i - 1).at(j - 1).at(l));
        }
      }
    }
  }
  int64_t ans = 1ll << 60;
  ans = min(ans, dp.at(n + 1).at(k).at(n + 1) / 2);
  cout << ans << endl;
}
