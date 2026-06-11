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

  int n;
  string s;
  cin >> n >> s;
  map<char, ll> mp;
  mp['R'] = 0, mp['G'] = 0, mp['B'] = 0;
  rep(i, 0, n) mp[s[i]]++;

  ll ans = mp['R'] * mp['G'] * mp['B'];

  rep(i, 0, n) {
    for (int k = i + 2; k < n; k += 2) {
      int j = i + (k - i) / 2;
      if (s[i] != s[j] && s[j] != s[k] && s[i] != s[k])
        ans--;
    }
  }

  cout << ans << endl;
}
