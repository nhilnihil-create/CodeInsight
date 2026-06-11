#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,t;
  cin >> n >> t;
  ll a[n],b[n];
  vector<vector<ll>> v;
  for(ll i=0;i<n;i++){
    ll c,d;
    cin >> c >> d;
    v.push_back({c,d});
  }
  sort(v.begin(),v.end());
  for(ll i=0;i<n;i++){
    a[i]=v[i][0];
    b[i]=v[i][1];
  }

  vector<vector<ll>> dp(n+1,vector<ll>(t+1,0));
  //i番目までの料理から選んで、時刻jまでに完食した場合の最大満足度

  for(ll i=0;i<n;i++){
    for(ll j=1;j<=t;j++){
      if(j>=a[i])dp[i+1][j]=max(dp[i][j],dp[i][j-a[i]]+b[i]);
      else dp[i+1][j]=dp[i][j];
    }
  }

  ll s=0;
  for(ll i=1;i<n;i++){
    s=max(dp[i][t-1]+b[i],s);
  }

  cout << s << endl;

}