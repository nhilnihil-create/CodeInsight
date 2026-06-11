#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
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
  ll n, k;
  cin >> n >> k;
  vl a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(all(a));
  sort(all(f), greater<ll>());
  vl c(n);
  rep(i, n) c[i] = a[i] * f[i];
  ll ng = -1, ok = a[n - 1] * f[0];
  while(ng + 1 < ok) {
    ll x = (ng + ok) / 2;
    ll cost = 0;
    rep(i, n) {
      ll now = (c[i] - x + f[i] - 1) / f[i];
      if(now > 0) cost += now;
    }
    if(cost > k)
      ng = x;
    else
      ok = x;
  }
  cout << ok << endl;
}