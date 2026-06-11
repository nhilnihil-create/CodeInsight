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
  vector<vector<int64_t>> counts(10, vector<int64_t>(10, 0));

  for (int64_t i = 1; i <= N; ++i) {
    const int64_t lowest = i % 10;
    int64_t temp = i;
    while (temp >= 10) {
      temp /= 10;
    }
    const int64_t highest = temp;
    // cerr << i << ": " << min(lowest, highest) << ", " << max(lowest, highest) << endl;
    ++counts[lowest][highest];
  }
  int64_t result = 0;
  for (int64_t i = 1; i < 10; ++i) {
    for (int64_t j = 1; j < 10; ++j) {
      int64_t temp_count = counts[i][j] * counts[j][i];
      result += temp_count;
    }
  }
  cout << result << endl;
  return 0;
}
