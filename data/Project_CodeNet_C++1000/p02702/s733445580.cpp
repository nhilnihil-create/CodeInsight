#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  map<int,int> mp;
  reverse(s.begin(), s.end());

  int k = 1, r = 0;
  for (int i = 0; i < s.size(); ++i) {
    int d = s[i] - '0';
    r = d * k + r;
    r %= 2019;

    ++mp[r];

    k *= 10;
    k %= 2019;
  }

  int ans = 0;

  for (auto e : mp) {
    int d = e.second;
    ans += (d * (d-1)) / 2;
  }

  cout << ans + mp[0] << '\n';

  return (0);
}