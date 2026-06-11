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
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

string s;

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

int solve(int i, int less){
  if(i == s.size()) return 1;

  if(less) return powMod(3, s.size()-i);
  if(s[i] == '0') return solve(i+1, false)%MOD;
  return (2*solve(i+1, false)+solve(i+1, true))%MOD;
}

signed main() {
  cin >> s;

  cout << solve(0, false)%MOD << endl;

  return 0;
}