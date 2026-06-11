#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isKaibun(string s)
{
  string t = s;
  reverse(s.begin(), s.end());

  return t == s;
}

void fail()
{
  cout << "No\n";
  exit(0);
}

void success()
{
  cout << "Yes\n";
  exit(0);
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.length();

  if (!isKaibun(s)) fail();
  if (!isKaibun(s.substr(0, (n-1)/2))) fail();
  if (!isKaibun(s.substr((n+3)/2-1))) fail();

  success();

  return (0);
}
