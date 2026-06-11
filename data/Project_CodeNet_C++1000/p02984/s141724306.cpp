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

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N);
  vector<int64_t> B(N, 0);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
    int64_t parity = (N - i + 1) % 2 == 0 ? 1 : -1;
    B[0] += parity * A[i];
  }
  cout << B[0];
  for (int64_t i = 1; i < N; ++i) {
    B[i] = -B[i - 1] + A[i - 1] * 2;
    cout << " " << B[i];
  }
  cout << endl;
  return 0;
}
