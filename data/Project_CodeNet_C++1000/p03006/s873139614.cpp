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
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<Pair> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i].first >> A[i].second;
  }
  map<Pair, int64_t> counts;
  sort(A.begin(), A.end());
  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = i + 1; j < N; ++j) {
      const Pair d = Pair(A[j].first - A[i].first, A[j].second - A[i].second);
      if (counts.find(d) == counts.end()) {
        counts[d] = 1;
      } else {
        ++counts[d];
      }
    }
  }
  int64_t max_count = 0;
  for (const auto count_p : counts) {
    if (count_p.second > max_count) {
      max_count = count_p.second;
    }
  }
  int64_t result = N - max_count;
  cout << result << endl;
  return 0;
}
