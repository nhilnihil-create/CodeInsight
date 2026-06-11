#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll INF=1000000000000000;
using P=pair<ll,ll>;
ll dp[1005][(1<<12)];
ll N,M;
int main(){
  cin>>N>>M;
  vector<P>A(M);
  for( ll i=0;i<M;i++){
  ll a,b;cin>>a>>b;ll sum=0;
    for(ll j=0;j<b;j++){
    ll c;cin>>c;sum+=pow(2,c-1);
    }P p(sum,a);A[i]=p;
  }for(ll i=0;i<=M;i++)
    for(ll j=0;j<(1<<N);j++)
      dp[i][j]=INF;
  dp[0][0]=0;
  for(ll i=1;i<=M;i++){
  ll c=A[i-1].first;
    ll a=A[i-1].second;
    for(ll j=0;j<(1<<N);j++)
      dp[i][j]=dp[i-1][j];
    for(ll j=0;j<(1<<N);j++){
    if(a+dp[i-1][j]<dp[i][c|j])
      dp[i][c|j]=a+dp[i-1][j];
     }
  }if(dp[M][(1<<N)-1]<INF)
    cout<<dp[M][(1<<N)-1]<<endl;
  else
    cout<<-1<<endl;
    
  return 0;
}