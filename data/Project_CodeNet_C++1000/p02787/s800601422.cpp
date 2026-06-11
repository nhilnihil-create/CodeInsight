#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll h,n;
  cin >>h >> n;
  ll a[n],b[n];
  for(ll i=0;i<n;i++)cin >> a[i] >> b[i];

  ll dp[30000]={};
  for(ll i=0;i<30000;i++)dp[i]=inf;
  dp[0]=0;

  for(ll i=0;i<30000;i++){
    for(ll j=0;j<n;j++){
      if(i-a[j]>=0)dp[i]=min(dp[i],dp[i-a[j]]+b[j]);
      //if(i==10 && dp[i]==1)cout << i << " " << j << endl;
    }
  }

  ll s=inf;

  for(ll i=h;i<30000;i++)s=min(s,dp[i]);

  cout << s << endl;

  //cout << dp[2] << endl;

}