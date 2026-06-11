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
  string s, t;
  cin >> s >> t;
  ll m = s.size();
  ll n = t.size();
  vector<vl> sum(26, vl(m + 1, 0));
  rep(i, 26) rep(j, m) sum[i][j + 1] = sum[i][j] + (s[j] == char(i + 'a'));
  ll now = 0, cnt = 0;
  rep(i, n) {
    ll c = t[i] - 'a';
    auto be = sum[c].begin();
    be += now;
    auto it = lower_bound(be, sum[c].end(), sum[c][now] + 1);
    if(it != sum[c].end()) {
      now = it - sum[c].begin();
      continue;
    }
    it = lower_bound(all(sum[c]), 1);
    if(it != sum[c].end()) {
      cnt++;
      now = it - sum[c].begin();
      continue;
    }
    cout << -1 << endl;
    return 0;
  }
  cout << cnt * m + now << endl;
}