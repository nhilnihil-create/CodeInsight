#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 繰り返しに情報によって，累乗a^b (mod m)を計算する
ll mpow(ll a, ll b, ll m) {
  if (b == 1) return a;
  // b奇数のとき
  if (b % 2) return (a * mpow(a, b-1, m)) %m;
  // b偶数のとき
  ll t = mpow(a, b/2, m) %m;
  return (t * t) % m;
}


int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  const ll M = 1000000007;
  //全体 2^n
  ll ans = mpow(2, n, M) -1;
  
  
  
  // a,b本からなる花の数を引く(nCa, nCbを引く)
  ll x = 1;
  for (ll i = n; i >= n-a+1; i--) {
    x *= i;
    x %= M;
  } 
    
  for (ll i = 1; i <= a; i++) {
    x *=  mpow(i, M-2, M);
    x %= M;
  }
  ans -= x % M;
  
  
  x = 1;
  for (ll i = n; i >= n-b+1; i--) {
    x *= i;
    x %= M;
  } 
  for (ll i = 1; i <= b; i++) {
    x *= mpow(i, M-2, M);
    x %= M;
  }
  ans -= x % M;
  
  cout << (ans + 2 * M) % M << endl;
}


