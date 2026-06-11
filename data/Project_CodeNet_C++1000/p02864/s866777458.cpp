/* monkukui 競技プログラミング用のテンプレート  (ここから) */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
using lnt = long long int;
using Graph = vector<vector<int>>;
using Wgraph = vector<vector<pair<int, long long int>>>;
constexpr long long int INF = 1001001001001001LL;
constexpr long long int MOD = 1000000007LL;
constexpr double PI = 3.1415926535897932;
constexpr long long int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
constexpr long long int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
inline void yes(){ cout << "yes" << endl; }
inline void Yes(){ cout << "Yes" << endl; }
inline void YES(){ cout << "YES" << endl; }
inline void no(){ cout << "no" << endl; }
inline void No(){ cout << "No" << endl; }
inline void NO(){ cout << "NO" << endl; }
inline void possible(){ cout << "possible" << endl; }
inline void Possible(){ cout << "Possible" << endl; }
inline void POSSIBLE(){ cout << "POSSIBLE" << endl; }
inline void impossible(){ cout << "impossible" << endl; }
inline void Impossible(){ cout << "Impossible" << endl; }
inline void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = 1; i <= (n); i++)
#define DREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define SREP(i,s,t) for(int i = s; i < t; i++)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define PB push_back

/* monkukui 競技プログラミング用のテンプレート (ここまで)*/

lint dp[310][310][310];

int main(){
  
  lint n, K; cin >> n >> K;
  vector<lint> h(n + 1, 0);
  for(int i = 0; i < n; i++) cin >> h[i + 1];
  for(int i = 0; i < 310; i++)
    for(int j = 0; j < 310; j++)
      for(int k = 0; k < 310; k++)
        dp[i][j][k] = INF;

  dp[0][0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k <= K; k++) {
        if(dp[i][j][k] == INF) continue;
        
        // むし
        if(k != K) dp[i + 1][j][k + 1] = min(dp[i + 1][j][k + 1], dp[i][j][k]);

        // とる
        lint cost = 0;
        lint pre_h = h[j];
        lint cur_h = h[i + 1];
        if(cur_h > pre_h) cost = cur_h - pre_h;
        dp[i + 1][i + 1][k] = min(dp[i + 1][i + 1][k], dp[i][j][k] + cost);
      }
    }
  }
  
  lint ans = INF;
  for(int j = 0; j <= n; j++) {
    for(int k = 0; k <= K; k++) {
      ans = min(ans, dp[n][j][k]);
    }
  }
  cout << ans << endl;
  return 0;
}
