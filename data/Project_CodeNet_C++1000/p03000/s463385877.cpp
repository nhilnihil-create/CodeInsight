#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,X;
  cin>>N>>X;

 
vector<ll> L(N);
  for(ll i=0;i<N;i++) {
    cin>>L[i];
  }
  
ll ans=1;
  ll z=0;
  for(ll i=0;i<N;i++) {
if(z+L[i]>X) {
break;
}
    z+=L[i];
    ans++;
  }
  
  cout<<ans<<endl;
}
 
    

  
  
  
  
  
