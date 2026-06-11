#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

ll modpow(ll a, ll p){
  ll ret = 1;
  while(p){
    if(p & 1) ret = ret * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ret;
}

int main(){
  int n; cin >> n;
  vector<ll> a(n); 
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> num(n);
  for(int i = 0; i < n; i++){
    num[a[i]]++;
  }
  ll ans = 1;
  for(int i = 1; i < n; i++){
    ans *= modpow(num[i-1], num[i]);
    ans %= mod;
  }
  if(num[0] != 1 || a[0] != 0) ans = 0;
  cout << ans << endl;
}