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

  int64_t H, W;
  cin >> H >> W;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<int64_t>> horizon(H);
  vector<vector<int64_t>> vertical(W);
  vector<vector<bool>> is_open(H, vector<bool>(W, true));

  for (int64_t r = 0; r < H; ++r) {
    string s;
    cin >> s;
    for (int64_t c = 0; c < W; ++c) {
      const char ch = s.c_str()[c];
      if (ch == '#') {
        horizon[r].push_back(c);
        vertical[c].push_back(r);
        is_open[r][c] = false;
      }
    }
  }

  for (int64_t r = 0; r < H; ++r) {
    horizon[r].push_back(-1);
    horizon[r].push_back(W);
    sort(horizon[r].begin(), horizon[r].end());
  }
  for (int64_t c = 0; c < W; ++c) {
    vertical[c].push_back(-1);
    vertical[c].push_back(H);
    sort(vertical[c].begin(), vertical[c].end());
  }

  int64_t result = 0;
  for (int64_t r = 0; r < H; ++r) {
    for (int64_t c = 0; c < W; ++c) {
      if (is_open[r][c]) {
        auto itr1 = lower_bound(vertical[c].begin(), vertical[c].end(), r);
        const int64_t top = *itr1;
        --itr1;
        const int64_t bottom = *itr1;

        auto itr2 = lower_bound(horizon[r].begin(), horizon[r].end(), c);
        const int64_t right = *itr2;
        --itr2;
        const int64_t left = *itr2;
        const int64_t temp = (top - bottom - 1) + (right - left - 1) - 1;
        result = max(result, temp);
      }
    }
  }

  cout << result << endl;
  return 0;
}
