#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  ll n, p;
  cin >> n >> p;
  string s;
  cin >> s;

  if (p == 2 || p == 5)
  {
    ll ans = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
      ll digit = s.at(i) - '0';
      if (digit % p == 0)
      {
        ans += i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  reverse(s.begin(), s.end());
  vector<ll> acc = {};
  map<ll, ll> cnts = {};
  cnts[0] = 1; // 範囲外を選択する場合を考慮

  ll d = 1;
  for (ll i = 0; i < s.size(); i++)
  {
    ll digit = s.at(i) - '0';
    if (i == 0)
    {
      ll val = digit % p;
      acc.push_back(val);
      if (cnts.count(val) > 0)
        cnts[val]++;
      else
        cnts[val] = 1;

      d *= 10;
      d %= p;

      continue;
    }
    else
    {
      ll val = d * digit + acc[i - 1];
      val %= p;
      acc.push_back(val);
      if (cnts.count(val) > 0)
        cnts[val]++;
      else
        cnts[val] = 1;

      d *= 10;
      d %= p;
    }
  }

  ll ans = 0;
  for (auto x : cnts)
  {
    if (x.second > 0)
    {
      ans += x.second * (x.second - 1) / 2;
    }
  }

  cout << ans << endl;
  return 0;
}
