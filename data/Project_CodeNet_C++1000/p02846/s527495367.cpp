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
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  ll sa = a1 * t1 + a2 * t2;
  ll sb = b1 * t1 + b2 * t2;
  if(sa == sb) {
    cout << "infinity" << endl;
    return 0;
  }
  if(sa < sb) {
    swap(sa, sb);
    swap(a1, b1);
    swap(a2, b2);
  }
  ll ans;
  if(a1 > b1)
    ans = 0;
  else {
    ll y = (b1 - a1) * t1;
    ll x = sa - sb;
    ans = y / x * 2 + 1;
    if(y % x == 0) ans--;
  }
  cout << ans << endl;
}