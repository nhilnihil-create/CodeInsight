#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,K;
  cin>>N>>K;
  vector<ll> H(N);
  for(ll i=0;i<N;i++) {
cin>>H[i];
  }
  sort(all(H));
  reverse(all(H));
  
  ll ans=0;
  for(ll i=K;i<N;i++) {
ans+=H[i];
  }
  
  cout<<ans<<endl;
}
