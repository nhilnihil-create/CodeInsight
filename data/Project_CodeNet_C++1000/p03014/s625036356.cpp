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
  vector<vector<vector<int>>> id(h, vector<vector<int>>(w, vector<int>(2)));
  vector<vector<int>> hl(h), vl(w);
  rep(i, h)
  {
    int c = 0, l = 0;
    rep(j, w)
      if (s[i][j] == '#')
      {
        hl[i].push_back(l);
        l = 0;
        c++;
      }
      else
      {
        l++;
        id[i][j][0] = c;
      }
    if (l != 0)
      hl[i].push_back(l);
  }
  rep(j, w)
  {
    int c = 0, l = 0;
    rep(i, h)
      if (s[i][j] == '#')
      {
        vl[j].push_back(l);
        l = 0;
        c++;
      }
      else
      {
        l++;
        id[i][j][1] = c;
      }
    if (l != 0)
      vl[j].push_back(l);
  }
  int ans = 0;
  rep(i, h)
    rep(j, w)
      if (s[i][j] == '.')
        ans = max(ans, hl[i][id[i][j][0]] + vl[j][id[i][j][1]] - 1);
  cout << ans << endl;
  return 0;
}