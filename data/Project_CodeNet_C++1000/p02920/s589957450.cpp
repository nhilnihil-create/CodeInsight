#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const ll INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(ll i=0;i<(ll)(s.size());++i) {
    cout << s[i];
    if(i == (ll)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll n; cin >> n;
  ll sz = 1;
  for(ll i=0;i<n;++i) {
    sz *= 2;
  }
  vector<ll> a(sz);
  for(ll i=0;i<sz;++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  vector<ll> nowv = {a[0]};
  vector<ll> sel(sz, false);
  sel[0] = true;
  ll now = 1;
  bool ok = true;
  while(now < sz) {
    sort(nowv.begin(), nowv.end());
    reverse(nowv.begin(), nowv.end());
    ll pos = 0;
    for(ll i=0;i<sz;++i) {
      if(pos == now) break;
      if(sel[i]) continue;
      if(a[i] < nowv[pos]) {
        sel[i] = true;
        nowv.push_back(a[i]);
        pos++;
      }
    }
    if(pos != now) {
      ok = false;
      break;
    }
    now *= 2;
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
