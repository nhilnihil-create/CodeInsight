#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = k; i <= n+1; i++) {
    ll a = 0;
    a += -1 * i * i;
    a += i * (n+1) + 1;
    ans += a;
    ans %= x;
  }
  cout << ans << endl;
  return 0;
}