#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  vector<ll> X(N);
  ll ans=10000000000;
  for(ll i=0;i<N;i++) {
cin>>X[i];
  }
  
  sort(all(X));
  for(ll i=X[0];i<=X[N-1];i++) {
    ll count=0;
  for(ll j=0;j<N;j++) {
count+=abs(i-X[j])*abs(i-X[j]);
  }
    ans=min(ans,count);
  }
  
  cout<<ans<<endl;
}
  
 
