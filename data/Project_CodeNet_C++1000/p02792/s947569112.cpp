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
  cin >> n;

  map<P, int> mp;
  rep(i, 1, n + 1) {
    string s = to_string(i);
    mp[make_pair(s[0]-'0',s[s.size() - 1] - '0')]++;
  }

  ll ans = 0;
  rep (i, 1, n + 1){
    string s = to_string(i);
    P p = make_pair(s[s.size() - 1] - '0', s[0]-'0');
    ans += mp[p];
  }

  cout << ans << endl;
}
