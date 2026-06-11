#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<ll> cnt(2019, 0);
  ll x = 0, ten = 1, tot = 0, ans = 0;
  rep(i, s.size()) {
    cnt[tot]++;
    x = (s[i] - '0') * ten;
    tot += x;
    tot %= 2019;
    ans += cnt[tot];
    ten *= 10;
    ten %= 2019;
  }
  cout << ans << endl;
  return 0;
}