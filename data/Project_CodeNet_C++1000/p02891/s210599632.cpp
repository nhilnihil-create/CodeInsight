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
  int64_t K;
  cin >> S >> K;
  const int64_t N = static_cast<int64_t>(S.length());

  if (S == string(N, S[0])) {
    cout << N * K / 2 << endl;
    return 0;
  }

  int64_t count_1 = 0;
  int64_t renzoku = 1;
  for (int64_t i = 1; i < N; ++i) {
    if (S[i - 1] == S[i]) {
      ++renzoku;
    } else {
      count_1 += renzoku / 2;
      renzoku = 1;
    }
  }
  if (renzoku > 0) {
    count_1 += renzoku / 2;
    renzoku = 1;
  }

  int64_t count_2 = 0;
  string SS = S + S;
  for (int64_t i = 1; i < 2 * N; ++i) {
    if (SS[i - 1] == SS[i]) {
      ++renzoku;
    } else {
      count_2 += renzoku / 2;
      renzoku = 1;
    }
  }
  if (renzoku > 0) {
    count_2 += renzoku / 2;
    renzoku = 1;
  }

  int64_t result;
  result = count_1 + (count_2 - count_1) * (K - 1);

  cout << result << endl;
  return 0;
}
