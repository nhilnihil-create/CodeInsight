#include <bits/stdc++.h>
using namespace std;

int main() {
  const int64_t mod = 1000000007;
  int n, m;
  cin >> n >> m;
  vector<int> s(n), t(m);
  for (int i = 0; i < n; i++) cin >> s.at(i);
  for (int i = 0; i < m; i++) cin >> t.at(i);
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1));
  for (int i = 0; i <= n; i++) dp.at(i).at(0) = 1;
  for (int i = 0; i <= m; i++) dp.at(0).at(i) = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp.at(i + 1).at(j + 1) = dp.at(i).at(j + 1) + dp.at(i + 1).at(j);
      if (s.at(i) != t.at(j)) {
        dp.at(i + 1).at(j + 1) += mod - dp.at(i).at(j);
      }
      dp.at(i + 1).at(j + 1) %= mod;
    }
  }
  cout << dp.at(n).at(m) << endl;
}
