#include <bits/stdc++.h>
#include <stdlib.h>
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
  ll n,k;
  cin>>n>>k;
  ll ans=0;
  for(int i=k;i<=n+1;i++){
    ans+=mod(i*(n-i+1)+1,MOD);
    ans=mod(ans,MOD);
  }
  cout<<ans<<endl;
  return 0;
}

