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
  ll n,a,b;
  cin>>n>>a>>b;
  ll mod=1000000007;
ll  ans=mod_pow(2,n,mod);

  ans--;
  ll A=1;
  ll B=1;
  for(ll i=0;i<a;i++) {
A*=(n-i);
    A%=mod;
  }
  for(ll i=0;i<b;i++) {
B*=(n-i);
    B%=mod;
  }
  
  for(ll i=2;i<=a;i++) {
A*=mod_pow(i,mod-2,mod);
    A%=mod;
  }
  
  for(ll i=2;i<=b;i++) {
B*=mod_pow(i,mod-2,mod);
    B%=mod;
  }
  
  
  ans-=(A+B);
  
  if(ans<0) {
while(ans<0) {
ans+=mod;
}
  }
  
  
  cout<<ans<<endl;
}
  
  
  
  

  
  
  
  
  
  
  
  
  