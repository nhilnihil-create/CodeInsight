#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int modPow(ll a, ll n, ll p) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    ll p=1000000007;
    ll x=1,y=1;
    for(int i = 0; i < a; i++) {
        x *= n-i;
        x %= p;
    }
    for(int i = 0; i < a; i++) {
        y *= i+1;
        y %= p;
    }
    ll s=1,t=1;
    for(int i = 0; i < b; i++) {
        s *= n-i;
        s %= p;
    }
    for(int i = 0; i < b; i++) {
        t *= i+1;
        t %= p;
    }
    ll ans=modPow(2,n,p)-1-x*modPow(y,p-2,p)-s*modPow(t,p-2,p);
    if(ans >=0){
        ans %= p;
    }
    else{
        ans *= -1;
        ans %= p;
        ans = p-ans;
        ans %= p;
    }

    cout << ans << endl;
    


    return 0;
}