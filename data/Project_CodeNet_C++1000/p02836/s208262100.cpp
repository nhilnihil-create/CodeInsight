#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int count = 0, l = s.size();
  rep(i, l / 2)
  {
    if (s[i] != s[l - 1 - i])
    {
      ++count;
    }
  }
  cout << count << endl;

  return 0;
}