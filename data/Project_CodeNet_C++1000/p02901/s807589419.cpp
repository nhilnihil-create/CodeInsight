#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e16;

int main(){

  ll n,m;
  cin >>n >> m;
  vector<vector<ll>> v(m);
  ll a[m],b[m];
  for(int i=0;i<m;i++){
    cin >> a[i] >> b[i];
    for(int j=0;j<b[i];j++){
      ll c;
      cin >>c ;
      v[i].push_back(c-1);
    }
  }

  
  vector<ll> dp((1<<n)+1,inf);
  dp[0]=0;



  for(ll b=0;b<(1<<n);b++){
    for(int i=0;i<m;i++){
      ll c=b;
      for(int j=0;j<v[i].size();j++)c=c | (1<<v[i][j]);
      dp[c]=min(dp[c],dp[b]+a[i]);
    }
  }

  if(dp[(1<<n)-1]==inf)cout << -1 << endl;
  else cout << dp[(1<<n)-1] << endl;
  




}