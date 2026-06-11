#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;

const int MOD = 1e9+7;

ll mpow(ll a, ll n){
  ll p = 1;
  while(n){
    if (n & 1) p = (p * a) % MOD;
    n >>= 1;
    a = (a * a) % MOD;
  }
  return p;
}

ll comb(ll n, ll m){
  ll mat=1, chi=1;
  rep(i, m){
    mat = (mat * (n-i)) % MOD;
    chi = (chi * (i+1)) % MOD;
  }
  return mat * mpow(chi, MOD - 2) % MOD;
}


int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int ans = mpow(2, n) - 1;
  ans -= comb(n, a);
  ans -= comb(n, b);
  
  while (ans < 0) ans += MOD;

  cout << ans << endl;
  return 0;
}