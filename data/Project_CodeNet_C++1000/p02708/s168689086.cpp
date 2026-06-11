#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;

  ll mod = 1000000000 + 7;
  ll ans = 0;
  
  for (ll i = k; i <= n; i++) {
    ans += (n*(n+1)/2 - (n-i)*(n-i+1)/2 - i*(i-1)/2 + 1) % mod;
    ans %= mod;
  }
  ans += 1;
  ans %= mod;

  cout << ans << endl;
}
