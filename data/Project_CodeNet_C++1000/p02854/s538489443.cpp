#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n; cin >> n;
  vector<ll> a(n);
  ll c = 0, ca = 0;
  rep(i,n) {
    cin >> a[i];
    ca += a[i];
  }
  ll ans = ca;
  rep(i,n) {
    c += a[i];
    ll d = ca - c;
    ans = min(abs(c - d), ans);
  }
  cout << ans << endl;
  return 0;
}