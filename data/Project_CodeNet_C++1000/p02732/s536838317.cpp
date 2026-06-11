#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
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
  int A[N];
  long long cnt[N];
  fill(cnt, cnt + N, 0);
  for (int i = 0; i < N; i++) cin >> A[i], cnt[--A[i]]++;
  long long sum = 0;
  for (int i = 0; i < N; i++) sum += cnt[i] * (cnt[i] - 1) / 2;
  for (int k = 0; k < N; k++) {
    cout << sum - (cnt[A[k]] * (cnt[A[k]] - 1) / 2)
                + ((cnt[A[k]] - 1) * (cnt[A[k]] - 2) / 2)
         << endl;
  }

  return 0;
}
