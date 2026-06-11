#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000
int main() {
  int N,M;
  cin>>N>>M;
  ll S[N],T[M];
  rep(i,N){cin>>S[i];}
  rep(i,M){cin>>T[i];}
  ll dp[N+1][M+1];
  rep(i,N+1){rep(j,M+1){dp[i][j]=0ll;}}
  rep(i,N+1){dp[i][0]=1ll;}
  rep(i,M+1){dp[0][i]=1ll;}
  rep(i,N){
    rep(j,M){
      dp[i+1][j+1]+=dp[i+1][j];
      dp[i+1][j+1]+=dp[i][j+1];
      if(S[i]!=T[j]){dp[i+1][j+1]-=dp[i][j];}
      dp[i+1][j+1]+=MOD;
      dp[i+1][j+1]%=MOD;
    }
  }
  cout<<dp[N][M];
}