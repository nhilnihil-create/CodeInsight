#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  if (s[0] == '>')
    s = "<" + s;
  if (s[s.size() - 1] == '<')
    s += ">";

  vector<ll> v;
  int n = s.size(), c = 0;
  bool b = true;
  rep(i, 0, n) {
    if (b) {
      if (s[i] == '<')
        c++;
      else {
        v.push_back(c);
        c = 1;
        b = !b;
      }
    } else {
      if (s[i] == '>')
        c++;
      else {
        v.push_back(c);
        c = 1;
        b = !b;
      }
    }
  }
  v.push_back(c);

  ll ans = 0;
  rep(i, 1, v.size()) {
    ll maxv = max(v[i], v[i - 1]);
    ll minv = min(v[i], v[i - 1]);
    minv--;
    ans += maxv * (maxv + 1) / 2;
    ans += minv * (minv + 1) / 2;
    i++;
  }

  cout << ans << endl;
}
