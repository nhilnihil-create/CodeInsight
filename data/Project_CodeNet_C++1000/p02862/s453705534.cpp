#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

// a^n (mod p) を繰り返し二乗法で計算する
ll nPower(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  
  // n が奇数のとき 
  if (n % 2) return (a * nPower(a, n-1, p)) %p;
  
  // n が偶数のとき
  ll t = nPower(a, n/2 , p) % p;
  return (t * t) % p;
}


ll Comb(ll n, ll r, ll p) {
  ll res = 1;
  
  for (ll i = n; i >= n - r + 1; i--) {
    res *= i;
    res %= p;
  }
  for (ll i = 1; i <= r; i++) {
    res *= nPower(i, p-2, p);
    res %= p;
  }
  return res % p;
}


int main () {
  
  ll X, Y;
  cin >> X >> Y;
  
  
  if ((2 * X - Y) % 3 == 0 && Y <= 2*X && X <= 2*Y) {
    ll a = (2*Y-X)/3, b = (2*X-Y)/3;
    cout << Comb(a+b, a, MOD) << endl;
  } else {
    cout << 0 << endl;
  }
}

