#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

char judge(char c) {
  if (c == 'r')
    return 'p';
  if (c == 's')
    return 'r';
  if (c == 'p')
    return 's';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  string result = "";
  rep(i, 0, n) {
    char c = judge(t[i]);
    if (i < k) {
      result += c;
    } else {
      if (result[i - k] == c)
        result += '?';
      else
        result += c;
    }
  }

  map<int, int> mp;
  rep(i, 0, n) mp[result[i]]++;

  ll ans = 0;
  ans += mp['r'] * r;
  ans += mp['s'] * s;
  ans += mp['p'] * p;
  cout << ans << endl;
}
