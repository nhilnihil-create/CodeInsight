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
  vl a(n), b(n), c(n - 1);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n - 1) cin >> c[i];
  ll ans = 0, last = -1;
  rep(i, n) {
    ans += b[a[i] - 1];
    if(a[i] - 1 == last) ans += c[a[i] - 2];
    last = a[i];
  }
  cout << ans << endl;
}