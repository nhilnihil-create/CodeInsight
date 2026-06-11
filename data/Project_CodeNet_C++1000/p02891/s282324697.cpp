/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int64_t Count(const string &S) {
  int64_t result = 0;
  const int64_t N = static_cast<int64_t>(S.length());
  vector<int64_t> counts;
  counts.push_back(1);
  for (int64_t i = 1; i < N; ++i) {
    if (S.c_str()[i] == S.c_str()[i - 1]) {
      ++counts[counts.size() - 1];
    } else {
      counts.push_back(1);
    }
  }
  if (counts.size() == 1U) {
    return -1;
  } else {
    for (int64_t i = 0; i < static_cast<int64_t>(counts.size()); ++i) {
      result += counts[i] / 2;
    }
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  int64_t K;
  cin >> S >> K;
  const int64_t N = static_cast<int64_t>(S.length());

  int64_t result;
  if (S == string(N, S[0])) {
    result = N * K / 2;
  } else {
    const int64_t first = Count(S);
    const int64_t second = Count(S + S);
    result = first + (second - first) * (K - 1);
  }
  cout << result << endl;

  return 0;
}
