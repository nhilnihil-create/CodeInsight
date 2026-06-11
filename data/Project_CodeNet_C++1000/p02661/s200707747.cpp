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
  vl a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  sort(all(a));
  sort(all(b));
  if(n % 2) {
    cout << b[n / 2] - a[n / 2] + 1 << endl;
    return 0;
  }
  ll x = (a[n / 2] + a[n / 2 - 1]);
  ll r = x % 2;
  x /= 2;
  ll y = (b[n / 2] + b[n / 2 - 1]);
  ll s = y % 2;
  y /= 2;
  ll ans = (y - x) * 2 + 1;
  if(r) ans--;
  if(s) ans++;
  cout << ans << endl;
}