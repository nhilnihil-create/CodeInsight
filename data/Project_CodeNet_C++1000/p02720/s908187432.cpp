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

  int64_t K;
  cin >> K;
  if (K < 10) {
    cout << K << endl;
    return 0;
  }
  vector<vector<int64_t>> lunluns(19);
  for (int64_t i = 1; i < 10; ++i) {
    lunluns[1].emplace_back(i);
  }
  int64_t count = 9;
  for (int64_t d = 2; d <= 18; ++d) {
    for (const int64_t &prev : lunluns[d - 1]) {
      for (int64_t next_1st = (prev % 10) - 1; next_1st <= (prev % 10) + 1;
           ++next_1st) {
        if (next_1st >= 0 && next_1st < 10) {
          const int64_t next = prev * 10 + next_1st;
          lunluns[d].emplace_back(next);
          ++count;
          if (count == K) {
            cout << lunluns[d].back() << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
