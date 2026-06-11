#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

ll m = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll ans = 0;
  rep(i,60) {
    ll y = 0;
    rep(j,n) if((a[j] >> i) & 1) y++;
    ll p = (y * (n - y)) % m;
    rep(j,i) p = (p * 2) % m;
    ans += p;
    ans %= m;
  }
  cout << ans << endl;
}