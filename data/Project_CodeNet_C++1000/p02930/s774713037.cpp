#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define debugArray(x, n)                                      \
  cerr << __LINE__ << ": " << #x << " = {";                   \
  for (long long hoge = 0; (hoge) < (long long)(n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];                   \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int N;
  cin >> N;
  int level[N][N];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      for (int b = 0; b < 10; b++)
        if (((i >> b) & 1) != ((j >> b) & 1)) {
          level[i][j] = b + 1;
          break;
        }
    }
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      cout << level[i][j] << (j == N - 1 ? '\n' : ' ');
  return 0;
}
