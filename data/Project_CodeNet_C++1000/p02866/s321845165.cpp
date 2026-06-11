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
/* const int MOD = 1000000007; */
const int MOD = 998244353;
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;


signed main() {
  int N; 
  cin >> N;

  vector<int> D(N);
  REP(i, N) cin >> D[i];

  map<int, int> m;
  REP(i, N) m[D[i]]++;

  bool ng = false;
  if(m[0] != 1) ng = true;
  if(D[0] != 0) ng = true;

  int ans = 1;
  FOR(i, 1, N){
    if(m[D[i]-1] == 0) ng = true;
    else{
      ans *= m[D[i]-1];
      ans %= MOD;
    }
  }

  if(ng) ans = 0;
  cout << ans << endl;

  return 0;
}