#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M),b(M),d(M);
  vector<vector<int>> c(M);
  rep(i,M) {
    cin >> a[i] >> b[i];
    c[i]=vector<int>(b[i]);
    rep(j,b[i]) {
      cin >> c[i][j];
      d[i]+=1<<(c[i][j]-1);
    }
  }
  vector<vector<int>> dp(M+1,vector<int>(1<<N,INF));
  dp[0][0]=0;
  rep2(i,1,M+1) {
    rep(j,1<<N) dp[i][j]=min(dp[i-1][j&(~d[i-1])]+a[i-1],dp[i-1][j]);
  }
  int ans=dp[M][(1<<N)-1];
  if(ans<INF) cout << ans << endl;
  else cout << -1 << endl;
}