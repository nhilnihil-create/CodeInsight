#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

ll f(string s);

int main() {
  string s; ll k;
  cin >> s >> k;

  bool identical = false;
  {
    map<char, int> mp;
    for (char c : s) mp[c]++;
    if (mp.size() == 1) identical = true; 
  }

  if (identical)
  {
    cout << s.size() * k / 2 << endl;
    return 0;
  }

  ll a1 = f(s);
  ll a2 = f(s + s);

  ll ans = a1 * k;
  if (a1 * 2 != a2) ans += (a2 % 2) * (k - 1);

  cout << ans << endl;
  return 0;
}

ll f(string s)
{
  ll ret = 0;
  size_t i = 1;
  while (i < s.size())
  {
    if (s[i] != s[i-1]) i++;
    else
    {
      ret++;
      i += 2;
    }
  }
  return ret;
}
