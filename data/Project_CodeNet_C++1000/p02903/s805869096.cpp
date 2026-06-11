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

  int64_t H, W, A_row, B_col;
  cin >> H >> W >> A_row >> B_col;
  vector<vector<int64_t>> result(H, vector<int64_t>(W, 0));
  for (int64_t r = B_col; r < H; ++r) {
    for (int64_t c = 0; c < A_row; ++c) {
      result[r][c] = 1;
    }
  }
  for (int64_t r = 0; r < B_col; ++r) {
    for (int64_t c = A_row; c < W; ++c) {
      result[r][c] = 1;
    }
  }

  for (int64_t r = 0; r < H; ++r) {
    int64_t zero = 0;
    int64_t one = 0;
    for (int64_t c = 0; c < W; ++c) {
      if (result[r][c] == 0) {
        ++zero;
      } else {
        ++one;
      }
    }
    if (min(zero, one) != A_row) {
      cout << "No" << endl;
    }
  }
  for (int64_t c = 0; c < W; ++c) {
    int64_t zero = 0;
    int64_t one = 0;
    for (int64_t r = 0; r < H; ++r) {
      if (result[r][c] == 0) {
        ++zero;
      } else {
        ++one;
      }
    }
    if (min(zero, one) != B_col) {
      cout << "No" << endl;
    }
  }

  for (int64_t r = 0; r < H; ++r) {
    for (int64_t c = 0; c < W; ++c) {
      cout << result[r][c];
    }
    cout << endl;
  }
  return 0;
}
