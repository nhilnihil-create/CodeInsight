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

  int64_t N, A, B;
  cin >> N >> A >> B;
  const int64_t d = abs(A - B);
  int64_t result;
  if (d % 2LL == 0) {
    result = d / 2L;
  } else {
    const int64_t x = (A - 1LL + B - 1LL + 1LL) / 2LL;
    const int64_t y = ((N - A) + (N - B) + 1) / 2LL;
    result = min(x, y);
  }
  cout << result << endl;

  return 0;
}
