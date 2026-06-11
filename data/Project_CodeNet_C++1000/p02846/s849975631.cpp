#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long T[2];
  cin >> T[0] >> T[1];
  long long A[2], B[2];
  cin >> A[0] >> A[1];
  cin >> B[0] >> B[1];
  B[0] -= A[0];
  B[1] -= A[1];
  long long C[2] = {abs(T[0] * B[0]), abs(T[1] * B[1])};
  if (B[0] / abs(B[0]) == B[1] / abs(B[1])) {
    cout << 0 << endl;
  } else if (C[0] == C[1]) {
    cout << "infinity" << endl;
  } else if (C[0] > C[1]) {
    cout << 0 << endl;
  } else {
    long long dif = C[1] - C[0];
    if (C[0] % dif == 0) {
      cout << C[0] / dif * 2 << endl;
    } else {
      cout << C[0] / dif * 2 + 1 << endl;
    }
  }
  return 0;
}
