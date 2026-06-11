#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

long long lcm(long long x, long long y) { return x / __gcd(x, y) * y; }

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N, M;
  cin >> N >> M;
  long long a[N];
  long long X = 1;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i] /= 2;
  }
  for (int i = 0; i < N; i++) {
    X = lcm(X, a[i]);
    if (X > M) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if (!(X / a[i] & 1)) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << M / X - M / (2 * X) << endl;
  return 0;
}
