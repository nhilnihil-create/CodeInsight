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
  string S;
  cin >> N >> S;
  enum RGBtype : int64_t { kR = 0L, kG, kB, kNumber };
  vector<vector<int64_t>> rgb(kNumber, vector<int64_t>());
  for (int64_t i = 0; i < N; ++i) {
    const char ch = S.c_str()[i];
    if (ch == 'R') {
      rgb[kR].push_back(i);
    } else if (ch == 'G') {
      rgb[kG].push_back(i);
    } else if (ch == 'B') {
      rgb[kB].push_back(i);
    }
  }

  vector<int64_t> rgb_index = {0, 1, 2};
  int64_t result = 0;
  do {
    for (auto first : rgb[rgb_index[0]]) {
      const auto second_start = upper_bound(rgb[rgb_index[1]].begin(), rgb[rgb_index[1]].end(), first);
      for (auto second = second_start; second != rgb[rgb_index[1]].end(); ++second) {
        const auto third_start = upper_bound(rgb[rgb_index[2]].begin(), rgb[rgb_index[2]].end(), *second);
        for (auto third = third_start; third != rgb[rgb_index[2]].end(); ++third) {
          const int64_t first_index = first;
          const int64_t second_index = *second;
          const int64_t third_index = *third;
          if (second_index - first_index != third_index - second_index) {
            ++result;
          }
        }
      }
    }
  } while (next_permutation(rgb_index.begin(), rgb_index.end()));
  cout << result << endl;

  return 0;
}
