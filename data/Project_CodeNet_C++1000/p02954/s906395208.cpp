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
  string s;
  cin >> s;
  vl l, p, c;
  ll now = 0, n = s.size();
  l.push_back(0);
  rep(i, n - 1) {
    now++;
    if(s[i] == 'R' && s[i + 1] == 'L') {
      p.push_back(i);
    } else if(s[i] == 'L' && s[i + 1] == 'R') {
      c.push_back(now);
      now = 0;
      l.push_back(i + 1);
    }
  }
  c.push_back(now + 1);
  vl ans(n, 0);
  rep(i, p.size()) {
    ans[p[i]] = ans[p[i] + 1] = c[i] / 2;
    ans[p[i] + (p[i] - l[i]) % 2] += c[i] % 2;
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endl;
  // rep(i, p.size()) cout << l[i] << ' ' << p[i] << ' ' << c[i] << endl;
}