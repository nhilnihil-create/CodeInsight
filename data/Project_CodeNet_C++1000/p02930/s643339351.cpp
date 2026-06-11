#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
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
constexpr int MOD = 1000000007;
constexpr int INF = 1e18;

using namespace std;


signed main() {
  int N;
  cin >> N;

  vector<vector<int>> vec(N, vector<int>(N, INF));

  REP(i, N) REP(j, N){
    int a = i+1, b = j+1;
    int cnt = 1;
    while(a || b){
      if(a%2 != b%2) break;
      cnt++;
      a /= 2; b /= 2;
    }
    vec[i][j] = cnt;
  }

  REP(i, N) FOR(j, i+1, N){
    cout << min(vec[i][j], vec[j][i]);
    SPBR(j, N);
  }

  return 0;
}