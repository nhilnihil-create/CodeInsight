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

  int64_t S;
  cin >> S;
  int64_t t = static_cast<int64_t>(sqrt(static_cast<double>(S)));
  ++t;
  const int64_t x1 = 1e9L;
  const int64_t y2 = (S + (x1 - 1)) / x1;
  const int64_t x2 = 1;
  const int64_t y1 = x1 * y2 - S;
  cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  // const int64_t L = static_cast<int64_t>(T.length());
  return 0;
}
