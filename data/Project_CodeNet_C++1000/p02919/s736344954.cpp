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

#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
  int N; 
  cin >> N;

  vector<int> A(N);
  REP(i, N) cin >> A[i];

  vector<int> o(N);
  iota(ALL(o), 0);

  sort(ALL(o), [&](int const & l, int const & r){
      return A[l] > A[r];
      });

  multiset<int> s;
  s.insert(-1); s.insert(-1);
  s.insert(N); s.insert(N);


  int ans = 0;
  REP(i, N){
    int I = o[i];

    auto it = s.upper_bound(I);

    int r1 = *it; it++;
    int r2 = *it; it--; it--;
    int l2 = *it; it--;
    int l1 = *it;


    ans += ((r2-r1)*(I-l2)+(r1-I)*(l2-l1))*A[I];
    s.insert(I);
  }

  cout << ans << "\n";

  return 0;
}