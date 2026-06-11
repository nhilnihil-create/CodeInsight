#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int MAXV =  3010;

int dp[MAXV][MAXV];

int main() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  int ans = 0;
  rep(i, n) {
    rep(j, t) {
      chmax(dp[i + 1][j], dp[i][j]);
      int nj = p[i].first + j;
      if (nj < t) chmax(dp[i + 1][nj], dp[i][j] + p[i].second);
    }
    chmax(ans, dp[i][t - 1] + p[i].second);

  }
  cout << ans << endl;
}