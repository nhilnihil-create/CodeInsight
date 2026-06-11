#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, V, P;
  cin >> N >> M >> V >> P;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end(), greater<int>());

  auto f = [&](int x) -> int64_t {
    int64_t res = 1LL * (P - 1) * M;
    for (int i = P - 1; i < N; i++) {
      res += min(M, A[x] + M - A[i]);
    }
    return res;
  };

  int lo = P - 1, hi = N - 1;
  while (lo < hi) {
    int mi = (lo + hi + 1) / 2;
    if (A[P - 1] - A[mi] <= M && f(mi) >= 1LL * M * V) {
      lo = mi;
    } else {
      hi = mi - 1;
    }
  }
  cout << lo + 1 << '\n';
  return 0;
}
