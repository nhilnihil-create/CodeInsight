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
  ll n, m;
  cin >> n >> m;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ng = -1, ok = 1e18;
  while(ng + 1 < ok) {
    ll x = (ng + ok) / 2;
    ll cnt = 0;
    vl b = a;
    rep(i, n) {
      while(b[i] > x) {
        b[i] /= 2;
        cnt++;
      }
    }
    if(cnt > m)
      ng = x;
    else
      ok = x;
  }
  rep(i, n) {
    while(a[i] > ok) {
      a[i] /= 2;
      m--;
    }
  }
  sort(all(a), greater<ll>());
  rep(i, min(m, n)) a[i] /= 2;
  cout << accumulate(all(a), 0LL) << endl;
}