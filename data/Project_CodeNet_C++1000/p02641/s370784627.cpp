#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
using P = pair<ll,ll>;
#define rep(i,n) for (ll i = 0; i<(ll)(n); i++)
#define mod 1000000007
#define pi 3.141592653589793
typedef vector<ll> vcl;

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t =rep_jijo(n,x/2);
        return t*t%mod;
  }
  return n*rep_jijo(n,x-1)%mod;
}
ll c2(ll n){
    return n*(n-1)/2;
}

int main(){
  ll x,n;
  cin>>x>>n;
  ll anl=300,anh=300;
  vcl p(n);
  rep(i,n) cin>>p[i];

  for(ll i=x;i>=0;i--){
      bool a=true;
      rep(j,n)if(p[j]==i)a=false;
      anl=i;
      if(a)break;
  }
for(ll i=x;i<=101;i++){
      bool a=true;
      rep(j,n)if(p[j]==i)a=false;
      anh=i;
      if(a)break;
  }

  if(abs(anl-x)>abs(anh-x))cout<<anh<<endl;
  else cout<<anl<<endl;
}
  