#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  long long sum_a = 0;
  for (auto &a : A) {
    cin >> a;
    sum_a += a;
  }
  long long ans = 0;
  auto test = [&](long long n) {
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
      M[i] = A[i] % n;
    }
    sort(M.begin(), M.end());
    vector<long long> MS(N);
    MS[0] = M[0];
    for (int i = 1; i < N; i++) {
      MS[i] = MS[i - 1] + M[i];
    }
    vector<long long> MSR(N + 1);
    for (int i = N - 1; i >= 0; i--) {
      MSR[i] = MSR[i + 1] + (n - M[i]);
    }
    long long k = 1e9 + 5;
    for (int i = 0; i < N; i++) {
      if (MS[i] == MSR[i + 1]) {
        k = MS[i];
        break;
      }
    }
    if (k <= K) {
      chmax(ans, n);
    }
  };
  for (long long i = 1; i * i <= sum_a; i++) {
    if (sum_a % i != 0) {
      continue;
    }
    test(i);
    if (sum_a / i != i) {
      test(sum_a / i);
    }
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
