/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, N;
  cin >> H >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N + 1);
  vector<int64_t> B(N + 1);
  for (int64_t i = 1; i <= N; ++i) {
    cin >> A[i] >> B[i];
  }
  const int64_t max_damage = *max_element(A.begin(), A.end());
  vector<vector<int64_t>> mp(N + 1, vector<int64_t>(H + max_damage + 1, INT64_MAX));
  for (auto &a : mp) {
    a[0] = 0;
  }
  for (int64_t i = 1; i <= N; ++i) {
    for (int64_t d = 1; d <= H + max_damage - 1; ++d) {
      mp[i][d] = mp[i - 1][d];
      if (d - A[i] >= 0 && mp[i - 1][d - A[i]] != INT64_MAX) {
        mp[i][d] = min(mp[i][d], mp[i - 1][d - A[i]] + B[i]);
      }
      if (d - A[i] >= 0 && mp[i][d - A[i]] != INT64_MAX) {
        mp[i][d] = min(mp[i][d], mp[i][d - A[i]] + B[i]);
      }
    }
  }
  int64_t result = INT64_MAX;
  for (int64_t d = H; d < H + max_damage; ++d) {
    result = min(result, mp[N][d]);
  }
  cout << result << endl;
  return 0;
}
