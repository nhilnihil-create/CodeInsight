#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
ll mod_pow(ll x,ll n,ll mod) {
ll res=1;
  while(n>0) {
if(n&1) {
res=res*x%mod;
}
  x=x*x%mod;
    n>>=1;
  }
  return res;
}
 


int main() {
  ll X,Y;
  cin>>X>>Y;
  if(X>2*Y||Y>2*X) {
    cout<<0<<endl;
    return 0;

  }
  else if((X+Y)%3!=0) {
cout<<0<<endl;
    return 0;
  }
  
  ll A=(X+Y)/3;
  ll B=X-A;
  
  
  ll mod=1000000007;
  ll ans=1;
  for(ll i=0;i<B;i++) {
ans*=(A-i);
    ans%=mod;
  }
  
  for(ll i=2;i<=B;i++) {
ans*=mod_pow(i,mod-2,mod)%mod;
    ans%=mod;
  }
  
  cout<<ans<<endl;
}
    
    

  
  
  
  
  
  
  
  
  
  
  
  