#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  ll ans = 1e18;
  rep(i, n) rep(j, n) {
    if(i == j) continue;
    ll x = p[j].first - p[i].first;
    ll y = p[j].second - p[i].second;
    ll cnt = 0;
    rep(a, n) {
      bool ok = false;
      rep(b, n) {
        if(a == b) continue;
        ll xx = p[b].first - p[a].first;
        ll yy = p[b].second - p[a].second;
        if(xx == x && yy == y) ok = true;
      }
      if(ok) cnt++;
    }
    ans = min(ans, n - cnt);
  }
  cout << ans << endl;
}