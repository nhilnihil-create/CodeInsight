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

  int64_t S;
  cin >> S;
  // const int64_t L = static_cast<int64_t>(T.length());
  const int64_t x1 = 1e9L;
  const int64_t x2 = 1L;
  int64_t y1, y2;
  for (int64_t i = S / 1e9L; i * x1 - S <= 1e9L; ++i) {
    y1 = i * x1 - S;
    if (y1 >= 0) {
      y2 = i;
      break;
    }
  }
  cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
