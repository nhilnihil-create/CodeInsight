// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
void solve();
main { solve(); return 0; }
// clang-format on

template<typename M>
void warshallFloyd(M &m, const int &n) {
  rep(k, n) rep(i, n) rep(j, n) cmin(m[i][j], m[i][k] + m[k][j]);
}

void solve() {
  int n;
  while (cin >> n, n) {
    vvi t(10, vi(10));
    rep(i, 10) rep(j, 10) t[i][j] = i == j ? 0 : INF;
    set<int> s;
    rep(i, n) {
      int a, b, c;
      cin >> a >> b >> c;
      s.insert(a), s.insert(b);
      t[a][b] = t[b][a] = c;
    }
    vi v(s.size());
    copy(all(s), v.begin());
    warshallFloyd(t, 10);
    int ms = INF, mp;
    rep(i, 10) {
      int s = 0;
      for (int j : v) s += t[i][j];
      if (cmin(ms, s)) mp = i;
    }
    cout << mp << ' ' << ms << endl;
  }
}