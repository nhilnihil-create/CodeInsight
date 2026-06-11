#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll gcd(ll &a,ll &b,ll &c) {
ll k=min(a,b);
  k=min(k,c);
  ll g;
  for(ll i=1;i<=k;i++) {
if(a%i==0&&b%i==0&&c%i==0) {
  g=i;
}
  }
  return g;
}




 
int main() {
 ll K;
  cin>>K;
  ll ans=0;
  for(ll i=1;i<=K-2;i++) {
for(ll j=i+1;j<=K-1;j++) {
for(ll h=j+1;h<=K;h++) {
  ans+=gcd(i,j,h);
}
}
  }
  
  ans*=6;
  ll t=0;
 for(ll i=1;i<=K;i++) {
for(ll j=1;j<=K;j++) {
  if(i==j) {
continue;
  }
t+=gcd(i,i,j);
}  
}

  
  t*=3;
  ans+=t;
 for(ll i=1;i<=K;i++) {
ans+=i;
 }
  
  cout<<ans<<endl;
}
