#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lpow(ll x, ll y, ll m){
  ll r = 1;
  x %= m;
  while (y) {
    if (y & 1) r = (r * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return r;
}

void fast_io() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
}

int main() {
  fast_io();

  ll n;
  cin >> n;
  ll mod = 1e9 + 7;
  ll ans = lpow(10, n, mod) - 2 * lpow(9, n, mod) + lpow(8, n, mod);
  cout << (ans + 2 * mod) % mod << '\n';
}
