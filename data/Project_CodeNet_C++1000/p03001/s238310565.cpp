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

  int64_t W, H, x, y;
  cin >> W >> H >> x >> y;
  if (x * 2 == W && y * 2 == H) {
    std::cout << std::setprecision(20) << static_cast<double>(W * H) / 2.0 << " " << 1 << endl;
  } else {
    std::cout << std::setprecision(20) << static_cast<double>(W * H) / 2.0 << " " << 0 << endl;
  }
  return 0;
}
