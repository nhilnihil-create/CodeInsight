#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

ll pd[3000];
ll rd[3000];
ll Ep(int x, int y){
  if(y == 0) return 1;
  if(y == 1) return x;
  ll r = Ep(x,y/2);
  if(y%2 == 1) return r *r%MOD *x%MOD;
  else return r *r%MOD;
}
ll Ftl(ll x){
  if(x == 1 || x == 0) return 1;
  if(pd[x] != 0) return pd[x];
  return pd[x] = Ftl(x-1) *x%MOD;
}
ll rFtl(ll x){
  if(x == 1 || x == 0) return 1;
  if(rd[x] != 0) return rd[x];
  return rd[x] = rFtl(x-1)*Ep(x,MOD-2)%MOD;
}
ll comb(ll m, ll n){
  if(m < n) return 0;
  return Ftl(m) *rFtl(n)%MOD *rFtl(m-n)%MOD;
}

int main(){
  int n, k;
  cin >> n >> k;
  int r = n-k;
  for(int i=1; i<=k; ++i){
    if(r+1<i) cout << 0 << endl;
    else{
      int ans = comb(r+1,r-i+1) * comb(k-1,k-i) %MOD;
      cout << ans << endl;
    }
  }
}