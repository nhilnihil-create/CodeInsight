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
  int n;
  ll k;
  cin>>n>>k;
  ll a[n],f[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>f[i];
  }
  sort(a,a+n);sort(f,f+n,greater<ll>());
  ll ng=-1,ok=1e13;
  while(ok-ng>1){
    ll mid=(ng+ok)/2;
    ll temp=0;
    for(int i=0;i<n;i++){
      if(mid<a[i]*f[i]){
        temp+=(a[i]*f[i]-mid+f[i]-1)/f[i];
      }
    }
    if(temp<=k) ok=mid;
    else ng=mid;
    //cout<<ng<<' '<<ok<<endl;
  }
  cout<<ok<<endl;
  return 0;
}