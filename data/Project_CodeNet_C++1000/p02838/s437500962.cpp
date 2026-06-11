#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll mod = 1000000007;
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  ll ans = 0;
  rep(i,0,60) {
    ll pop = 0;
    rep(j,0,n) {
      if (a[j] & ((ll)1 << i)) pop++;
    }
    ans += ((((((ll)1 << i) % mod) * pop) % mod) * (n-pop)) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
