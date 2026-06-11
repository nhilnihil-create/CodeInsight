#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  map<string, ll> mp;
  rep(i, 0, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  ll ans = 0;
  for (auto m : mp) {
    ll x = m.second;
    x--;
    ans += (x * (x + 1)) / 2;
  }

  cout << ans << endl;
}
