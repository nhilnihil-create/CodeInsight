#include<bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 1; i < (ll)n; i++)

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }

int main() {
  ll k;
  cin >> k;
  ll ans = 0;
  
  rep(a,k+1){
    rep(b,k+1){
      rep(c,k+1){
        ans += gcd(gcd(a,b),c);
      }
    }
  }
  cout << ans << endl;
}