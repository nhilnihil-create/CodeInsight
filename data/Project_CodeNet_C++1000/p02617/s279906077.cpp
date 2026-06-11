#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  ll n;
  cin>>n;
  ll ans=0;
  for(ll i=0;i<n;i++){
    ans+=(i+1)*(n-i);
  }
  for(ll i=0;i<n-1;i++){
    ll u,v;
    cin>>u>>v;u--;v--;
    if(u>v) swap(u,v);
    ans-=(u+1)*(n-v);
  }
  cout<<ans<<endl;
  return 0;
}
