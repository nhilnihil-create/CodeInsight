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

  string S;
  cin >> S;
  const int64_t L = static_cast<int64_t>(S.length());
  reverse(S.begin(), S.end());
  vector<int64_t> N(L + 1, 0);
  unordered_map<int64_t, int64_t> m;
  int64_t d = 1;
  m[0] = 1;
  for (int64_t i = 1; i <= L; ++i) {
    const int64_t v = static_cast<int64_t>(S[i - 1] - '0');
    N[i] = (N[i - 1] + d * v) % 2019;
    if (m.find(N[i]) == m.end()) {
      m[N[i]] = 1;
    } else {
      ++m[N[i]];
    }
    d *= 10;
    d %= 2019;
  }
  int64_t result = 0;
  for (auto a : m) {
    result += a.second * (a.second - 1) / 2;
  }
  cout << result << endl;
  return 0;
}
