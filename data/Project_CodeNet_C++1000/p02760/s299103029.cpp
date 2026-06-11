#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
#define rreps(i, n) for(int i=((int)(n)); i>0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pl(s) cout << (s) << "\n";
#define pls(...) {bool space = false; for(auto i : __VA_ARGS__) (cout << (space?" ":"") << i), space = true; cout << "\n";}
#define plexit(s) {cout << (s) << "\n"; exit(0);}
#define yes(s) cout << ((s)?"Yes":"No") << "\n";
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long; using ull = unsigned long long; using ld = long double;
template<typename T = int> using V = vector<T>; template<typename T = int> using P = pair<T, T>;
using Vi = V<int>; using Vl = V<ll>; using Vd = V<ld>; using VVi = V<Vi>; using VVl = V<Vl>; using Pi = P<int>; using Pl = P<ll>; using Pd = P<ld>;
constexpr ll MOD = 1000000007; constexpr int INF = (1 << 30) - 1; constexpr ll INFL = 1LL << 60; constexpr ld EPS = 1e-12; constexpr ld PI = 3.141592653589793238462643383279;

int main(void) {
  VVi a(3, Vi(3)); rep(i,3) rep(j,3) cin >> a[i][j];
  int n; cin >> n;
  rep(q,n) {
    int b; cin >> b;
    rep(i,3) rep(j,3) {
      if (a[i][j] == b) a[i][j] = -1;
    }
    bool ok = true;
    rep(i,3) if (a[i][0] != -1) ok = false;
    if (ok) plexit("Yes")
    ok = true;
    rep(i,3) if (a[i][1] != -1) ok = false;
    if (ok) plexit("Yes")
    ok = true;
    rep(i,3) if (a[i][2] != -1) ok = false;
    if (ok) plexit("Yes")
    
    ok = true;
    rep(j,3) if (a[0][j] != -1) ok = false;
    if (ok) plexit("Yes")
    ok = true;
    rep(j,3) if (a[1][j] != -1) ok = false;
    if (ok) plexit("Yes")
    ok = true;
    rep(j,3) if (a[2][j] != -1) ok = false;
    if (ok) plexit("Yes")

    ok = true;
    if (a[0][0] != -1 || a[1][1] != -1 || a[2][2] != -1) ok = false;
    if (ok) plexit("Yes")
    ok = true;
    if (a[0][2] != -1 || a[1][1] != -1 || a[2][0] != -1) ok = false;
    if (ok) plexit("Yes")
  }
  pl("No")
  return 0;
}
