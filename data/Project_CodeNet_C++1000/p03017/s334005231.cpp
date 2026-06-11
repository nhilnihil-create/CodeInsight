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
  ll n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;
  bool ans = true;
  rep(i, n - 1) if(s[i] == '#' && s[i + 1] == '#' && i > a && (i < c || i < d))
      ans = false;
  if(c == d)
    ans = false;
  else if(c > d) {
    bool ok = false;
    ll cnt = 0;
    rep(i, n) {
      if(s[i] == '.')
        cnt++;
      else
        cnt = 0;
      if(b < i && cnt > 2 && i <= d + 1) ok = true;
    }
    if(!ok) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}