#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  
  sort(all(vec));
  reverse(all(vec));
  ll ans=0;
  
  
  ans+=vec[0];
  ll i=1;
  ll count=1;
  while(count<N-1) {
ans+=vec[i]*2;
    count+=2;
    i++;
  }
  
  if(count>N-1) {
ans-=vec[i-1];
  }
  
  cout<<ans<<endl;
}
  
  
  
  
  
  
  
