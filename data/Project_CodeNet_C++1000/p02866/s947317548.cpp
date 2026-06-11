#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { 
  INIT(){cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

int powMod(int n, int p) {
  int res = 1;
  while (p) {
    if (p & 1) (res *= n) %= MOD;
    (n *= n) %= MOD;
    p >>= 1;
  }
  return res;
}
int invMod(int n) {
  return powMod(n, MOD - 2);
}

signed main() {
  int N;
  cin >> N;

  bool ng = false;
  map<int, int> m;
  REP(i, N){
    int a;
    cin >> a;
    m[a]++;
    if(i == 0 && a != 0) ng = true;
  }

  int ans = 1;
  if(m[0] != 1) ng = true;
  for(auto p : m){
    if(p.first == 0) continue;
    if(m[p.first-1] == 0) ng = true;
    (ans *= powMod(m[p.first-1], p.second)) %= MOD;
  }

  if(ng) ans = 0;
  cout << ans << "\n";

  return 0;
}