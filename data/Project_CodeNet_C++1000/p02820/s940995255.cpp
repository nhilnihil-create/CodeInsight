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
  ll n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  ll ans = 0;
  vb v(n, false);
  rep(i, n) {
    if(i >= k && t[i - k] == t[i] && v[i - k]) {
      if(i < 2 * k || (t[i - 2 * k] != t[i - k]) || !v[i - 2 * k]) continue;
    }
    if(t[i] == 'r')
      ans += p;
    else if(t[i] == 's')
      ans += r;
    else
      ans += s;
    v[i] = true;
  }
  cout << ans << endl;
}