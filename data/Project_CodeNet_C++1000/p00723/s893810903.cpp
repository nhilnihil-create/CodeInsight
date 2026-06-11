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

string rev(string x) {
  reverse(all(x));
  return x;
}

void solve() {
  int n;
  cin >> n;
  while (n--) {
    string w;
    cin >> w;
    set<string> p;
    rep(i, w.size() - 1) {
      string s = w.stlice(0, i), t = w.stlice(i + 1, w.size() - 1);
      p.insert(s + t);
      p.insert(rev(s) + t);
      p.insert(s + rev(t));
      p.insert(rev(s) + rev(t));
      p.insert(t + s);
      p.insert(rev(t) + s);
      p.insert(t + rev(s));
      p.insert(rev(t) + rev(s));
    }
    cout << p.size() << endl;
  }
}