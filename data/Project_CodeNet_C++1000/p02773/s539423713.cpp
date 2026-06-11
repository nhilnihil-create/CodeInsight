#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  map<string, int> map;
  for (ll i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    map[s]++;
  }
  vector<string> ans;
  ll maxv = 0;
  for (auto itr = map.begin(); itr != map.end(); itr++)
  {
    if (itr->second > maxv)
    {
      ans.clear();
      maxv = itr->second;
    }
    else if (itr->second < maxv)
    {
      continue;
    }

    ans.push_back(itr->first);
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << endl;
  }
}
