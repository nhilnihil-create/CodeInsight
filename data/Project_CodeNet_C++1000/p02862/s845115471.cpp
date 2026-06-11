#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

ll mod = 1e9+7;
ll calc(ll a,ll p,ll m){
  if(p==0) return 1;
  if(p%2==0){
    ll d = calc(a,p/2,m);
    return d*d%m;
  }else{
    return a*calc(a,p-1,m)%m;
  }
}

ll comb(ll n,ll k){
  if(n<k||k<0) return 0;
  ll sum = 1;
  ll a = 1;
  for(int i=0;i<k;i++){
    sum *= n-i;
    sum %= mod;
    a *= i+1;
    a %= mod;
  }
  ll res = sum*calc(a,mod-2,mod)%mod;
  return res;
}
int main(){
  ll x,y; cin >> x >> y;
  ll r = (x+y)%3;
  if(r!=0){
    cout << 0 << endl;
    return 0;
  }
  ll n = (x+y)/3;
  ll k = x - n;
  ll ans = comb(n,k)%mod;
  cout << ans << endl;
}