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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll nc = b / c - (a - 1) / c;
  ll nd = b / d - (a - 1) / d;
  ll g = c / gcd(c, d) * d;
  ll ncd = b / g - (a - 1) / g;
  ll cup = nc + nd - ncd;
  ll ans = b - a + 1 - cup;
  cout << ans << endl;
}