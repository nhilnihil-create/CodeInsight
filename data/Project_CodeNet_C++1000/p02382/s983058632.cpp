// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979;
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int n) { return n & 1; }
constexpr bool even(const int n) { return ~n & 1; }
template<typename T = int> T in() { T x; cin >> x; return x; }
template<typename T = int> T in(T &&x) { T z(forward<T>(x)); cin >> z; return z; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &x : v) is >> x; return is; }
template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> ostream &operator<<(ostream &os, const vector<vector<T>> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : "\n"); return os; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { int n = v.size(); rep(i, n) os << v[i] << (i == n - 1 ? "" : " "); return os; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << ' ' << p.second; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
// clang-format on

template<typename T> T minkowskiDistance(const vector<T> &a, const vector<T> &b, const int &p) {
  int n = a.size();
  T x = 0;
  rep(i, n) x += pow(abs(a[i] - b[i]), p);
  return pow(x, 1.0 / p);
}

template<typename T> T chebyshevDistance(const vector<T> &a, const vector<T> &b) {
  int n = a.size();
  T x = 0;
  rep(i, n) cmax(x, abs(a[i] - b[i]));
  return x;
}

main {
  int n;
  cin >> n;
  auto a = in(vector<double>(n));
  auto b = in(vector<double>(n));
  cout << prec(32);
  cout << minkowskiDistance(a, b, 1) << endl;
  cout << minkowskiDistance(a, b, 2) << endl;
  cout << minkowskiDistance(a, b, 3) << endl;
  cout << chebyshevDistance(a, b) << endl;
}

