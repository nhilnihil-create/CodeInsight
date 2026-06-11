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
  int N, K;
  cin >> N >> K;
  long long A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  long long low = 0, high = 1e9 + 10;
  while (high - low > 1) {
    long long mid = (low + high) / 2;
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
      cnt += (A[i] - 1) / mid;
      if (cnt > K) break;
    }
    if (cnt > K)
      low = mid;
    else
      high = mid;
  }
  cout << high << endl;
  return 0;
}
