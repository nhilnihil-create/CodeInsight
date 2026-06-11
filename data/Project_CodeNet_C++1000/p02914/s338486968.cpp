#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  long long ans = 0;
  long long A[N];
  for (int i = 0; i < N; i++) cin >> A[i], ans ^= A[i];
  for (int j = 0; j < 60; j++) {
    int cnt = 0;
    for (int i = 0; i < N; i++) cnt += (A[i] >> j) & 1;
    if (cnt & 1)
      for (int i = 0; i < N; i++) A[i] = A[i] & (A[i] ^ (1ll << j));
  }
  vector<long long> bases;
  for (int i = 0; i < N; i++) {
    for (long long b : bases) A[i] = min(A[i], A[i] ^ b);
    if (A[i]) bases.push_back(A[i]);
  }
  sort(bases.rbegin(), bases.rend());
  long long tmp = 0;
  for (long long b : bases) tmp = max(tmp, tmp ^ b);
  ans += tmp << 1;
  cout << ans << '\n';
  return 0;
}
