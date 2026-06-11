#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  string s, t;
  cin >> s >> t;
  vector<vector<int>> pos(26);
  rep(i, s.size())
    pos[s[i] - 'a'].push_back(i + 1);
  vector<vector<int>> nxt(s.size() + 1, vector<int>(26, -1));
  rep(i, s.size() + 1)
    rep(j, 26)
    {
      if (pos[j].empty())
        continue;
      auto itr = upper_bound(pos[j].begin(), pos[j].end(), i);
      if (itr == pos[j].end())
        nxt[i][j] = pos[j][0];
      else
        nxt[i][j] = *itr;
    }
  ll ans = 0;
  int pre = 0, crt;
  for (char& c : t)
  {
    if (nxt[pre][c - 'a'] == -1)
    {
      puts("-1");
      return 0;
    }
    crt = nxt[pre][c - 'a'];
    if (pre >= crt)
      ans += s.size() - pre + crt;
    else
      ans += crt - pre;
    pre = crt;
  }
  cout << ans << endl;
  return 0;
}