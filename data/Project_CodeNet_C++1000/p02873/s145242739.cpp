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
  const int64_t length = static_cast<int64_t>(S.length());
  const int64_t N = length + 1;
  vector<int64_t> A(N, 0);
  for (int64_t i = 0; i < length; ++i) {
    const int64_t n = i + 1;
    if (S.c_str()[i] == '<') {
      A[n] = max(A[n - 1] + 1, A[n]);
    }
  }
  for (int64_t i = length - 1; i >= 0; --i) {
    const int64_t n = i + 1;
    if (S.c_str()[i] == '>') {
      A[n - 1] = max(A[n - 1], A[n] + 1);
    }
  }
  int64_t sum = 0;
  for (int64_t i = 0; i < N; ++i) {
    sum += A[i];
  }
  cout << sum << endl;

  return 0;
}
