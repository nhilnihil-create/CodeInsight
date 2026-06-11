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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;


signed main() {
  int N, M; 
  cin >> N >> M;

  vector<int> A(M), B(M);
  vector<vector<int>> C(M);
  REP(i, M){
    cin >> A[i] >> B[i];
    C[i].resize(B[i]);
    REP(j, B[i]){
      cin >> C[i][j];
      C[i][j]--;
    }
  }

  // i個まで見て, 開けた宝箱がj(bit)の時の最小値
  int dp[M+1][(1<<N)+1];
  REP(i, M+1) REP(j, (1<<N)) dp[i][j] = INF;
  dp[0][0] = 0;

  REP(i, M) REP(j, (1 << N)){
    int bit = 0;
    REP(k, B[i]) bit |= (1 << C[i][k]);

    chmin(dp[i+1][j], dp[i][j]);
    chmin(dp[i+1][(j | bit)], dp[i][j]+A[i]);
  }

  int ans = dp[M][(1<<N)-1];
  if(ans == INF) ans = -1;
  cout << ans << "\n";

  return 0;
}