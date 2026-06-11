#include <bits/stdc++.h>
#define BIT(n) (1LL << (n))
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPB(i, n) for (int i = 0; i < BIT(n); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORA(i, n) for (auto &&i : n)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define DEBUG(x) cerr << #x << ": " << x << "\n"
#define DEBUG2(x, y) cerr << #x << ": " << x << " " << #y << ": " << y << "\n"
#define DEBUG3(x, y, z)                                                        \
  cerr << #x << ": " << x << " " << #y << ": " << y << " " << #z << ": " << z  \
       << "\n"
#define PRINTALL(V)                                                            \
  for (auto v : (V)) {                                                         \
    cout << v << " ";                                                          \
  }                                                                            \
  cout << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
#define pint pair< int, int >
#define ld long double
using namespace std;
template < class T > bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template < class T > using vec = std::vector< T >;
template < class T > void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int xy[110][3];
inline int calc(pint x, pint y) {
  return (y.snd - x.snd) * (y.snd - x.snd) + (y.fst - x.fst) * (y.fst - x.fst);
}
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int N;
  cin >> N;
  vec< pint > lis(N);
  REP(i, N) {
    int x, y;
    cin >> x >> y;
    lis[i] = mp(x, y);
  }
  sort(ALL(lis), [](const pint &a, const pint &b) {
    return atan2(a.snd, a.fst) < atan2(b.snd, b.fst);
  });
  int ans = 0;
  REP(i, N) {
    int vx = 0, vy = 0;
    REP(j, N) {
      vx += lis[(i + j) % N].fst;
      vy += lis[(i + j) % N].snd;
      chmax(ans, vx * vx + vy * vy);
    }
  }
  print(sqrt(ans * 1.0));
}
