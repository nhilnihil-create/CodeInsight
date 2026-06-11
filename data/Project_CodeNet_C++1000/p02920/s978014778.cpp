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
#define PRINTALL(V)    \
  for (auto v : (V)) { \
    cerr << v << " ";  \
  }                    \
  cerr << "\n";
#define ALL(v) v.begin(), v.end()
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define epb emplace_back
#define int long long
using namespace std;
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> using vec = std::vector<T>;
template <class T> void print(const T &x) { cout << x << "\n"; }
const int MOD = 1000000007, INF = 1061109567;
const double EPS = 1e-10, PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
  cin.tie(0), ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int N;
  cin >> N;

  vec<int> a(BIT(N));
  vec<int> b;

  REP(i, BIT(N)) cin >> a[i];
  sort(ALL(a));
  reverse(ALL(a));
  b.pb(a[0]);
  a[0] = 0;

  REP(i, N) {
    sort(ALL(a));
    reverse(ALL(a));
    sort(ALL(b));
    reverse(ALL(b));
    int index = 0;
    REP(j, BIT(i)) {
      while (1) {
        if (index == (int)a.size() || a[index] == 0) {
          print("No");
          return 0;
        }
        if (b[j] > a[index]) {
          b.pb(a[index]);
          a[index] = 0;
          index++;
          break;
        }
        index++;
      }
    }
  }
  print("Yes");
}

/*
教訓としてwhile文は複雑になりそうだったら中でbreak指定したほうが良い。
適宜bool変数を用意して、Noを出力するかどうか決定すればよかった。
降順の配列bを用意して各々の要素においてできるだけ大きなaの要素を取る。貪欲にやっている。
取ったあとは、bに組み込み取ったことを示すためにもとの配列の値は0にする。
尺取りでやるためaのindexは変化しない。(+1する)最後まで到達してしまったら終了。
各々の日ごとにa,bはソートしておく。
解説の方法では完全二部木でやっている。
 */