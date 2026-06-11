//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n;cin>>n;ll t;cin>>t;
  vector<vvl> dp (3100,vvl(3100,vl(2)));
  for(ll i=1;i<=n;i++){
    ll a,b;cin>>a>>b;
    rep(j,t){
      dp[i][j][0]=dp[i-1][j][0];
      dp[i][j][1]=dp[i-1][j][1];
      if(j>=a){
        dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-a][0]+b);
        dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-a][1]+b);
      }
      dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]+b);
    }
  }
  ll ans=0;
  rep(j,t){
    rep(k,2)ans=max(ans,dp[n][j][k]);
  }
  cout<<ans<<endl;
  /*rep(i,n+1){
    rep(j,t){
      rep(k,2)cout<<dp[i][j][k]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;*/
}