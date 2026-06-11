#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h)
    cin >> s[i];
  vector<vector<int>> c(h, vector<int>(w, -1));
  rep(i, h)
    rep(j, w)
    {
      if (s[i][j] == '#')
        continue;
      int last = j + 1;
      while (last < w && s[i][last] == '.')
        last++;
      for (int k=j; k<last; k++)
        c[i][k] += last - j;
      j = last - 1;
    }
  rep(j, w)
    rep(i, h)
    {
      if (s[i][j] == '#')
        continue;
      int last = i + 1;
      while (last < h && s[last][j] == '.')
        last++;
      for (int k=i; k<last; k++)
        c[k][j] += last - i;
      i = last - 1;
    }
  int ans = 0;
  rep(i, h)
    rep(j, w)
      ans = max(ans, c[i][j]);
  cout << ans << endl;
  return 0;
}