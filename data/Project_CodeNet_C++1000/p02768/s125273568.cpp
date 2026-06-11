#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll MOD = 1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}
ll modComb(ll n,ll a){
  ll x=1,y=1;
  rep(i,a){
    x*=n-i;
    x%=MOD;
    y*=i+1;
    y%=MOD;
  }
  y=modPow(y,MOD-2);
  return (x*y)%MOD;
}


int main(){
  ll n,a,b,ans;
  cin >> n >> a >> b;
  ans=modPow(2,n);
  ans+=2*MOD;
  ans--;
  
  ans-=modComb(n,a);
  ans-=modComb(n,b);
  ans%=MOD;
  cout << ans << endl;
}
