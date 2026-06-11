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


signed main() {
  int N, D, A; 
  cin >> N >> D >> A;

  vector<pair<int, int>> vec(N);
  REP(i, N) cin >> vec[i].first >> vec[i].second;

  sort(ALL(vec));

  vector<int> X(N), H(N);
  REP(i, N) tie(X[i], H[i]) = vec[i];
  X.emplace_back(INF); H.emplace_back(0);

  int ans = 0;
  vector<int> cnt(N+1, 0);
  REP(i, N){
    if(i != 0) cnt[i] += cnt[i-1];
    H[i] -= cnt[i]*A;
    if(H[i] <= 0) continue;

    int now = (H[i]+A-1)/A;
    ans += now;
    cnt[i] += now;
    // x[i]+Dより上
    int t = upper_bound(ALL(X), X[i]+2*D)-X.begin();
    cnt[t] -= now;
  }

  cout << ans << endl;

  return 0;
}