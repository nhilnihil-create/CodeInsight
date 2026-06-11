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
  int h, w;
  while (cin >> h >> w, h) {
    vs s(h);
    rep(i, h) cin >> s[i];
    int x = 0;
    rep(i, h) rep(j, w) {
      int t = 0;
      fn<void(int, int, char)> f = [&](int i, int j, char c) {
        if (i < 0 || j < 0 || i >= h || j >= w || c == '-' || s[i][j] != c) return;
        s[i][j]  = '-';
        int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
        rep(k, 4) f(i + di[k], j + dj[k], c);
      };
      x += s[i][j] != '-';
      f(i, j, s[i][j]);
    }
    cout << x << endl;
  }
}