#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
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
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  long long p[A + 1], q[B + 1], r[C + 1];
  for (int i = 0; i < A; i++) cin >> p[i];
  for (int i = 0; i < B; i++) cin >> q[i];
  for (int i = 0; i < C; i++) cin >> r[i];
  p[A] = q[B] = r[C] = 0;
  sort(p, p + A);
  reverse(p, p + A + 1);
  sort(q, q + B);
  reverse(q, q + B + 1);
  sort(r, r + C);
  reverse(r, r + C + 1);
  long long sum = 0;
  for (int i = 1; i <= X; i++) sum += p[i];
  for (int j = 1; j <= Y; j++) sum += q[j];
  int i = X, j = Y, k = 1;
  while (i > 0 || j > 0 && k <= C) {
    if (i == 0 && q[j] >= r[k]) break;
    if (j == 0 && p[i] >= r[k]) break;
    if (min(p[i], q[j]) >= r[k]) break;
    if (j == 0 || p[i] < q[j]) {
      sum -= p[i--];
    } else {
      sum -= q[j--];
    }
    sum += r[k++];
  }
  cout << sum << endl;
  return 0;
}
