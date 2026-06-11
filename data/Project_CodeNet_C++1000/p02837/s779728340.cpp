#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<vector<int>> evid(n, vector<int>(n, -1));//-1:証言無し 1:正直　2:不親切
  rep(i, n)
  {
    int a;
    cin >> a;
    rep(j, a)
    {
      int x, y;
      cin >> x >> y;
      x--;
      evid[i][x] = y;
    }
  }
  int ans = 0;
  rep(i, 1<<n)
  {
    bool chk = true;
    rep(j, n)
    {
      if ((i & 1<<j) == 0)
        continue;
      rep(k, n)
      {
        if (evid[j][k] == -1)
          continue;
        if ((i>>k & 1) != evid[j][k])
          chk = false;
      }
    }
    if (chk)
      ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
  return 0;
}