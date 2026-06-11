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
  ll MOD=1000000007;
  int n,k;
  cin>>n>>k;
  ll amari[k+1];
  for(int i=1;i<k+1;i++){
    amari[i]=modpow(i,n,MOD);
  }
  ll kosuu[k+1];
  ll ans=0;
  for(int i=k;i>=1;i--){
    kosuu[i]=amari[k/i];
    for(int j=2*i;j<=k;j+=i){
      kosuu[i]=mod(kosuu[i]-kosuu[j],MOD);
    }
    ans=mod(ans+kosuu[i]*i,MOD);
  }
  cout<<ans<<endl;
  return 0;
}
