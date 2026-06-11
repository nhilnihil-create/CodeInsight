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

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<pair<int64_t, bool>>> A(N, vector<pair<int64_t, bool>>());
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    for (int64_t j = 0; j < a; ++j) {
      int64_t person, y;
      cin >> person >> y;
      A[i].push_back(pair<int64_t, bool>(person - 1, (y == 1)));
    }
  }
  int64_t result = 0;
  for (int32_t b = 0; b < (1 << N); ++b) {
    const bitset<15> bs(b);
    bool is_okay = true;
    for (int64_t person = 0; person < N; ++person) {
      if (bs[person]) {
        for (const auto p : A[person]) {
          if (bs[p.first] != p.second) {
            is_okay = false;
            break;
          }
        }
      }
      if (!is_okay) {
        break;
      }
    }
    if (is_okay) {
      result = max(result, static_cast<int64_t>(bs.count()));
      // cerr << bs << endl;
    }
  }
  cout << result << endl;
  return 0;
}
