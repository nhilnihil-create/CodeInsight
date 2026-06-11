#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N,M;
  cin >> N >> M;
  vi a(M),b(M),x(M);
  vvi c(M);
  rep(i,M) {
    cin >> a[i] >> b[i];
    c[i]=vi(b[i]);
    rep(j,b[i]) {
      cin >> c[i][j];
      x[i]+=1<<(c[i][j]-1);
    }
  }
  
  vvi dp(M+1,vi(1<<N,INF));
  dp[0][0]=0;
  rep(i,M) {
    rep(j,1<<N) dp[i+1][j]=dp[i][j];
    rep(j,1<<N) dp[i+1][j|x[i]]=min(dp[i+1][j|x[i]],dp[i][j]+a[i]);
  }
  
  int ans=dp[M][(1<<N)-1];
  if(ans!=INF) cout << ans << endl;
  else cout << -1 << endl;
}