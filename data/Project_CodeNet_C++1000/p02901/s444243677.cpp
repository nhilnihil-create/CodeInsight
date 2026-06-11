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
  ll n;cin>>n;ll m;cin>>m;
  vvl dp(1010,vl(1<<12));
  rep(i,m+1){
    rep(j,1LL<<n)dp[i][j]=INF;
  }
  dp[0][0]=0;
  for(ll i=1;i<=m;i++){
    ll a,b;cin>>a>>b;
    vl vec(b);
    rep(j,b){
      cin>>vec[j];vec[j]--;
    }
    rep(j,1LL<<n){
      dp[i][j]=min(dp[i-1][j],dp[i][j]);
      ll part=j;
      for(auto x:vec){
        if(!(part&(1LL<<x)))part^=1<<x;
        dp[i][part]=min(dp[i][part],dp[i][j]+a);
      }
    }
  }
  if(dp[m][(1LL<<n)-1]>=INF)cout<<-1<<endl;
  else cout<<dp[m][(1LL<<n)-1]<<endl;
  /*rep(i,m+1){
    rep(j,1LL<<n)cout<<dp[i][j]<<" ";
    cout<<endl;
    cout<<endl;
  }*/
}