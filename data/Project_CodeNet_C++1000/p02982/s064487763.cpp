#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
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

map<ll, ll> primeFactor(ll n) {
  map<ll, ll> res;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

int main() {
  ll n, d;
  cin >> n >> d;
  vector<vl> x(n, vl(d));
  rep(i, n) rep(j, d) cin >> x[i][j];
  ll ans = 0;
  rep(i, n - 1) rep2(j, i + 1, n) {
    ll s = 0;
    rep(k, d) s += pow(x[i][k] - x[j][k], 2);
    auto pf = primeFactor(s);
    bool ok = true;
    for(auto v : pf)
      if(v.second % 2) ok = false;
    if(ok) ans++;
  }
  cout << ans << endl;
}