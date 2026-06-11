#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  string s;
  ll k;
  cin >> s >> k;
  vl a;
  ll now = 1;
  rep2(i, 1, s.size()) {
    if(s[i - 1] == s[i])
      now++;
    else {
      a.push_back(now);
      now = 1;
    }
  }
  a.push_back(now);
  ll ans = 0;
  if(a.size() == 1) {
    ans = a[0] * k / 2;
  } else if(s[0] == s.back()) {
    rep2(i, 1, a.size() - 1) ans += a[i] / 2;
    ans *= k;
    ll ex = a[0] + a.back();
    ans += a[0] / 2 + a.back() / 2 + ex / 2 * (k - 1);
  } else {
    rep(i, a.size()) ans += a[i] / 2;
    ans *= k;
  }
  cout << ans << endl;
}
