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

  int64_t A, B, N;
  cin >> A >> B >> N;
  int64_t max_val = (A * min(B - 1, N)) / B;
  cout << max_val << endl;

  return 0;
}
