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
  int N;
  cin >> N;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  sort(ALL(A));

  int P = 0, Q = 0;
  REP(i, N) if(A[i] < 0)  P++;
  REP(i, N) if(A[i] >= 0) Q++;
  if(Q == 0) Q++, P--;
  if(P == 0) P++, Q--;


  vector<pair<int, int>> ans;
  FOR(i, P+1, N){
    ans.emplace_back(A[0], A[i]);
    A[0] -= A[i];
  }
  REP(i, P){
    ans.emplace_back(A[P], A[i]);
    A[P] -= A[i];
  }

  cout << A[P] << endl;
  REP(i, ans.size()){
    cout << ans[i].first << " " << ans[i].second << endl;
  }


  return 0;
}