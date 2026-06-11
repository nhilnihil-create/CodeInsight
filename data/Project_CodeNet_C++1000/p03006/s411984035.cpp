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
  vector<Pair> A(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());
  map<Pair, int64_t> counts;
  int64_t max_count = 0;
  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = i + 1; j < N; ++j) {
      const Pair p(A[j].first - A[i].first, A[j].second - A[i].second);
      if (counts.find(p) == counts.end()) {
        counts[p] = 1;
      } else {
        ++counts[p];
      }
      max_count = max(max_count, counts[p]);
    }
  }
  int64_t result = N - max_count;
  cout << result << endl;
  return 0;
}
