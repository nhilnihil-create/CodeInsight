#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1000)
  {
    string t = "000";
    int a = i;
    rep(j, 3)
    {
      if (a == 0)
        break;
      t[2 - j] = a % 10 + '0';
      a /= 10;
    }
    int cnt = 0;
    bool found = false;
    rep(j, s.size())
    {
      if (s[j] == t[cnt])
      {
        cnt++;
        if (cnt == 3)
        {
          found = true;
          break;
        }
      }
    }
    if (found)
      ans++;
  }
  cout << ans << endl;
  return 0;
}