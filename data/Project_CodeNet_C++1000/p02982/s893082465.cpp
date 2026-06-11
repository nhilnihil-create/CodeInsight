#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,D;
  cin>>N>>D;
  vector<vector<ll>> vec(N,vector<ll>(D));
  for(ll i=0;i<N;i++) {
for(ll j=0;j<D;j++) {
cin>>vec[i][j];
}
  }
  
  ll ans=0;
  for(ll i=0;i<N-1;i++) {
  
for(ll j=i+1;j<N;j++) {
  ll kyori=0;
  for(ll h=0;h<D;h++) {
kyori+=(vec[i][h]-vec[j][h])*(vec[i][h]-vec[j][h]);
  }
  
  for(ll k=1;k<1000;k++) {
if(k*k==kyori) {
ans++;
  break;
}
  }
}
  }
  
  cout<<ans<<endl;
}
  
  
  
