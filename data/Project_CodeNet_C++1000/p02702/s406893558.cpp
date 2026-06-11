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

  string S;
  cin >> S;
  constexpr int32_t kP = 2019;
  const int64_t L = static_cast<int64_t>(S.length());
  vector<int64_t> P(L, 0);
  P[L - 1] = 1;
  for (int32_t i = 1; i < L; ++i) {
    P[L - 1 - i] = (P[L - i] * 10) % kP;
  }
  vector<int64_t> A(L, 0);
  vector<int64_t> sum(L + 1, 0);
  vector<int64_t> hist(kP, 0);
  sum[0] = 0;
  hist[0]++;
  for (int64_t i = 0; i < L; ++i) {
    const int64_t n = static_cast<int64_t>(S.c_str()[i] - '0');
    A[i] = (n * P[i]) % kP;
    sum[i + 1] = (sum[i] + A[i]) % kP;
    hist[sum[i + 1]]++;
  }
  int64_t result = 0;
  for (int64_t i = 0; i < static_cast<int64_t>(hist.size()); ++i) {
    if (hist[i] >= 2) {
      result += hist[i] * (hist[i] - 1) / 2;
    }
  }
  cout << result << endl;

  return 0;
}
