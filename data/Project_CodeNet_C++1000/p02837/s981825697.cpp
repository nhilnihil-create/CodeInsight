/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<pair<int64_t, bool>>> A(N);
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    for (int64_t j = 0; j < a; ++j) {
      int64_t x, y;
      cin >> x >> y;
      A[i].emplace_back(x - 1, (y == 1));
    }
  }
  int64_t result = 0;
  for (int64_t b = 0; b < (1L << N); ++b) {
    bitset<15> bs(b);
    bool is_okay = true;
    for (int64_t i = 0; i < N; ++i) {
      // cerr << b << ", " << i << " " << __LINE__ << endl;
      if (bs[i]) {
        for (auto p : A[i]) {
          if (bs[p.first] != p.second) {
            is_okay = false;
          }
        }
      }
      if (!is_okay) {
        break;
      }
    }
    if (is_okay) {
      result = max(result, static_cast<int64_t>(bs.count()));
    }
  }
  cout << result << endl;
  return 0;
}
