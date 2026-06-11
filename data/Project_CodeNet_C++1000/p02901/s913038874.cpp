//2020-06-21 06:58:21
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
const int INF = 1e9;
int dp[1001][1<<12];
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, m; cin >> n >> m;
   vector<pair<int, int>> keys;
   rep(i,m){
      int a, b; cin >> a >> b;
      int state = 0;
      rep(j,b){
         int c; cin >> c;
         state += (1<<(c-1));
      }
      keys.push_back(make_pair(a, state));
   }
   rep(i,1001)rep(j,1<<12)dp[i][j] = INF;
   dp[0][0] = 0;
   rep(i,keys.size()){
      rep(j,1<<n){
         if (dp[i][j] != -1){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            dp[i+1][j | keys[i].second] = min(dp[i+1][j | keys[i].second], dp[i][j]+keys[i].first);
         }
      }
   }
   cout << (dp[m][(1<<n)-1]==INF ? -1 : dp[m][(1<<n)-1]) << endl;
}