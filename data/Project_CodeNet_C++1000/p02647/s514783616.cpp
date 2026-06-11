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

  int64_t N, K;
  cin >> N >> K;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N + 2, 0);
  for (int64_t i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int64_t k = 0; k < K; ++k) {
    vector<int64_t> prev(N + 2, 0);
    swap(A, prev);
    for (int64_t i = 1; i <= N; ++i) {
      ++A[max(i - prev[i], 0L)];
      --A[min(i + prev[i] + 1, N + 1)];
    }
    bool same = true;
    for (int64_t i = 1; i <= N + 1; ++i) {
      A[i] += A[i - 1];
      if (A[i] != prev[i]) {
        same = false;
      }
    }
    if (same) {
      break;
    }
  }
  for (int64_t i = 1; i <= N; ++i) {
    if (i != 1) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  return 0;
}
