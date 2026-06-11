#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int n;
  cin >> n;
  string s[n];
  map<string, ll> num;
  rep(i, n) {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
    num[s[i]]++;
  }

  ll ans = 0;
  for (auto i : num) {
    if (i.second == 1) continue;
    ans += i.second * (i.second - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}
