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
  vl a(n + 1);
  rep(i, n + 1) cin >> a[i];
  if(n == 0) {
    if(a[0] == 1)
      cout << 1 << endl;
    else
      cout << -1 << endl;
    return 0;
  }
  if(a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  vector<P> p(n + 1);
  p[n] = P(a[n], a[n]);
  p[0] = P(1, 1);
  for(int i = n - 1; i >= 1; i--) {
    ll bl = p[i + 1].first;
    ll br = p[i + 1].second;
    ll l = (bl + a[i] + 1) / 2;
    ll r = br + a[i];
    p[i] = P(l, r);
  }
  ll ans = 1, now = 1;
  bool ok = true;
  rep2(i, 1, n + 1) {
    ll l = p[i].first;
    ll r = p[i].second;
    if(r < now || now * 2 < l) ok = false;
    now = min(r, now * 2);
    ans += now;
    now -= a[i];
  }
  cout << (ok ? ans : -1) << endl;
}