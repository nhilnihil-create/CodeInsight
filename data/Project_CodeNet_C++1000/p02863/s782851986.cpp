#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;

int main() {
  int N,T;
  cin>>N>>T;
  ll A[N],B[N];
  vector<P>C(N);
  rep(i,N){
    ll a,b;
    cin>>a>>b;
    C[i]=P(a,b);
  }
  sort(C.begin(),C.end());
  rep(i,N){
    A[i]=C[i].first;
    B[i]=C[i].second;
  }
  ll dp[N+1][T+1][2];
  rep(i,N+1){rep(j,T+1){dp[i][j][0]=0ll;dp[i][j][1]=0ll;}}
  rep(i,N){
    rep(j,T){
      //ふつーに選ぶとき
      if(j+A[i]<T){dp[i+1][j+A[i]][0]=max(dp[i+1][j+A[i]][0],dp[i][j][0]+B[i]);}
      dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]);
      //最後を選ぶとき
      dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+B[i]);
      if(j+A[i]<T){dp[i+1][j+A[i]][1]=max(dp[i+1][j+A[i]][1],dp[i][j][1]+B[i]);}
      dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]);
    }
  }
  ll ans=0ll;
  rep(i,T+1){
    ans=max(ans,dp[N][i][1]);
    ans=max(ans,dp[N][i][0]);
  }
  cout<<ans<<endl;
}
