#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
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
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;
struct INIT { 
  INIT(){cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int A, B, M; 
  cin >> A >> B >> M;

  int mina = INF, minb = INF;

  vector<int> a(A);
  REP(i, A){
    cin >> a[i];
    chmin(mina, a[i]);
  }

  vector<int> b(B);
  REP(i, B){
    cin >> b[i];
    chmin(minb, b[i]);
  }

  int ans = mina+minb;
  REP(i, M){
    int x, y, c;
    cin >> x >> y >> c;
    chmin(ans, a[x-1]+b[y-1]-c);
  }
  cout << ans << "\n";

  return 0;
}