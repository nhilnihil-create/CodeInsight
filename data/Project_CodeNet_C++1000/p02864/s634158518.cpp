#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7;
int main(){
  vector<ll> vec;
  vec.push_back(0);
  ll n,k;
  cin>>n>>k;
  ll dp[305][305]={0};
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    vec.push_back(a);
  }
  for(int i=0;i<305;i++){
    for(int j=0;j<305;j++) dp[i][j]=174417441744;
  }
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n-k;j++){
      for(int k=0;k<i;k++){
        dp[i][j]=min(dp[i][j],dp[k][j-1]+max((ll)0,(vec[i]-vec[k])));
      }
    }
  }
  ll ans=174417441744;
  for(int i=0;i<=n;i++) ans=min(ans,dp[i][n-k]);
  cout<<ans<<endl;
}
