#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modPow(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}

ll choose(ll n, ll r, ll mod){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * modPow(div, mod - 2, mod) % mod;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll kit = 10e8 + 7;

    ll ans = modPow(2, n, kit);
    ans--;
    ans -= choose(n, a, kit);
    ans -= choose(n, b, kit);
    ans %= kit;
    if (ans < 0){
        ans += kit;
    }

    cout << ans << endl;
}
