#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, n)
  {
    if (s[i] == 'A')
    {
      if ("ABC" == s.substr(i, 3))
      {
        ans++;
        i += 2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}