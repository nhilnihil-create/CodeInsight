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
  vector<int64_t> L(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());

  int64_t result = 0;
  for (int64_t a = 0; a < N; ++a) {
    for (int64_t b = a + 1; b < N; ++b) {
      const int64_t end = static_cast<int64_t>(lower_bound(L.begin(), L.end(), L[a] + L[b]) - L.begin());
      const int64_t begin = b + 1;
      const int64_t c_count = (end - begin);
      result += c_count;
      // cerr << L[a] << ", " << L[b] << ", count=" << c_count << endl;
    }
  }
  cout << result << endl;
  return 0;
}
