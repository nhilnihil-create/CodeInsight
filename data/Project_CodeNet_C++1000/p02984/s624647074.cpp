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

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll l = -1, r = 1e18;
  while(l + 1 < r) {
    ll x = (l + r) / 2;
    vl b(n + 1);
    b[0] = x * 2;
    rep(i, n) b[i + 1] = 2 * a[i] - b[i];
    if(b[n] < b[0])
      r = x;
    else if(b[n] > b[0])
      l = x;
    else {
      rep(i, n) cout << b[i] << '\n';
      return 0;
    }
  }
}