#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
vector<pair<ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
ll X,L;
    cin>>X>>L;
    vec[i]=make_pair(X+L,X-L);
  }
  
  sort(all(vec));
  ll ans=1;
  ll s=vec[0].first;
  for(ll i=1;i<N;i++) {
if(vec[i].second>=s) {
ans++;
  s=vec[i].first;
}
  }
  
  cout<<ans<<endl;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  