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

  int64_t N;
  cin >> N;
  int64_t result = 0;
  if (N % 2 == 0) {
    N /= 2;
    int64_t p = 5;
    while (p <= N) {
      result += N / p;
      p *= 5;
    }
  } else {
    result = 0;
  }
  cout << result << endl;
  return 0;
}
