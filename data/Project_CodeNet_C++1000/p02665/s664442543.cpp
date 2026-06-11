#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int64_t> A(N + 1);
  for (int i = 0; i < N + 1; i++) {
    cin >> A[i];
  }
  if (N != 0 && A[0] != 0) {
    cout << -1 << '\n';
    return 0;
  }
  if (N == 0) {
    if (A[0] == 1) {
      cout << 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
    return 0;
  }
  vector<pair<int64_t, int64_t>> X(N + 1);
  X[N] = make_pair(A[N], A[N]);
  for (int i = N - 1; i > -1; i--) {
    int64_t a = X[i + 1].first / 2 + (X[i + 1].first % 2) + A[i];
    int64_t b = X[i + 1].second + A[i];
    X[i] = make_pair(a, b);
  }
  int64_t res = 1;
  vector<pair<int64_t, int64_t>> Y(N + 1);
  Y[0] = make_pair(1, 1);
  for (int i = 1; i < N + 1; i++) {
    int64_t a = Y[i - 1].first;
    int64_t b = 2 * Y[i - 1].second;
    if ((a <= X[i].first && X[i].first <= b) ||
        (a <= X[i].second && X[i].second <= b)) {
      Y[i] = make_pair(max(a, X[i].first) - A[i], min(b, X[i].second) - A[i]);
      res += Y[i].second + A[i];
    } else {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << res << '\n';
  return 0;
}
