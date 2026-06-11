#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  map<string, ll> anagram;
  for (ll i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    anagram[s]++;
  }
  ll ans = 0;
  for (auto itr = anagram.begin(); itr != anagram.end(); itr++)
  {
    if (itr->second > 1)
    {
      ll num = itr->second;
      ans += (ll)num * (num - 1) / 2;
    }
  }
  cout << ans << endl;
}
