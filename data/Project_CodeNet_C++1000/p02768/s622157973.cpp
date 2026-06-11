#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
#define repr2(i, s, n) for(ll i = n-1; i >= s; i++)
using namespace std;

const ll mod = 1000000007;
ll modPow(ll a, ll n){
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  if (n % 2 == 1) return (a * modPow(a, n-1)) % mod;
  ll t = modPow(a, n/2);
  return (t * t) % mod;
}

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  
  ll ans = modPow(2, n) - 1;
  ll x1 = 1, y1 = 1, x2 = 1, y2 = 1;
  rep2(i, n-a+1, n+1) x1 = (x1 * i) % mod;
  rep2(i, 1, a+1) y1 = (y1 * i) % mod;
  rep2(i, n-b+1, n+1) x2 = (x2 * i) % mod;
  rep2(i, 1, b+1) y2 = (y2 * i) % mod;
  ll ac = (x1 * modPow(y1, mod-2)) % mod;
  ll bc = (x2 * modPow(y2, mod-2)) % mod;
  ans = (ans - ac - bc + 2*mod) % mod;
  
  cout << ans << endl;
  return 0;
}