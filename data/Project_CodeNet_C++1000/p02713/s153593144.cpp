#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()


ll gcd(ll a,ll b) {
  if(b==0) {
return a;
  }
  a%=b;
 ll s= gcd(b,a);
  return s;
}
  

 
int main() {
ll K;
  cin>>K;
  ll ans=0;
  for(ll i=1;i<=K;i++) {
for(ll j=1;j<=K;j++) {
  for(ll h=1;h<=K;h++) {
ans+=gcd(gcd(i,j),h);
  }
}
    
  }

  
  
  cout<<ans<<endl;
}
