#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rep1(i,n) for (int i=1; i<=(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define fst first
#define scd second
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0, M = 1e9+7;
  ll km = ((k*(k-1)) % M * (M/2+1)) % M;
  rep(i,n) {
    ll ac = 0, c = 0;
    rep(j,n) {
      if (a[i] > a[j]) {
        if (j > i) c++;
        ac++;
      }
    }
    ll rt = (c * k) % M;
    ll mt = (ac * km) % M;
    ans = (ans + (rt + mt) % M) % M;
  }
  cout << ans << endl;
  return 0;
}