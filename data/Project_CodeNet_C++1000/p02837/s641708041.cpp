#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int xy[15][15];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      xy[i][j] = -1;
    }
  }

  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++)
    {
      int x, y;
      cin >> x >> y;
      --x;
      xy[i][x] = y;
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++)
  {
    vector<int> d(n);
    for (int j = 0; j < n; j++)
    {
      if (i >> j & 1)
      {
        d[j] = 1;
      }
    }
    int flg = 1;
    for (int j = 0; j < n; j++)
    {
      if (d[j])
      {
        for (int k = 0; k < n; k++)
        {
          if (xy[j][k] == -1)
          {
            continue;
          }
          if (xy[j][k] != d[k])
          {
            flg = 0;
          }
        }
      }
    }
    if (flg)
    {
      ans = max(ans, __builtin_popcount(i));
    }
  }
  cout << ans << endl;
}
