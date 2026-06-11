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
  unordered_map<string, int64_t> m;
  for (int64_t i = 0; i < N; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (m.find(s) == m.end()) {
      m[s] = 1;
    } else {
      ++m[s];
    }
  }
  int64_t result = 0;
  for (const auto &p : m) {
    result += p.second * (p.second - 1) / 2;
  }
  cout << result << endl;
  return 0;
}
