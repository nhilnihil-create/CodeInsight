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

int N, M, V, P; 
vector<int> A;

bool f(int x){
  // M人がV問の点数を1上げる
  // 上位P-1個と自分に点数を上げる
  // 残りは小さいところから上げていく
  if(N-P <= x) return true;
  
  if(A[x]+M < A[N-P]) return false;
  // 残りM*Vまで上げなければいけない
  // 1個につき上げれる点数はM
  // A[x]+Mになるまで上げれば良い
  int cnt = 0;
  REP(i, N-P+1){
    if(i == x) continue;
    cnt += min(M, A[x]+M-A[i]);
  }
  if(cnt >= M*(V-P)) return true;
  return false;
}

signed main() {
  cin >> N >> M >> V >> P;

  A.resize(N);
  REP(i, N) cin >> A[i];

  sort(ALL(A));

  int ok = N-1;
  int ng = -1;
  while(ok-ng > 1){
    int mid = (ok+ng)/2;
    if(f(mid)) ok = mid;
    else ng = mid;
  }

  cout << A.end()-lower_bound(ALL(A), A[ok]) << endl;

  return 0;
}