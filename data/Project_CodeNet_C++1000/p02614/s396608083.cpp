#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W, K;

  cin >> H >> W >> K;

  vector<vector<char>> c(H, vector<char>(W));

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c.at(i).at(j);
    }
  }

  int ans = 0;

  for (int i = 0; i < (1 << H); i++)
  {
    for (int j = 0; j < (1 << W); j++)
    {
      int cnt = 0;
      for (int k = 0; k < H; k++)
      {
        for (int l = 0; l < W; l++)
        {
          if ((i & (1 << k)) || (j & (1 << l)))
          {
            continue;
          }
          if (c.at(k).at(l) == '#')
          {
            cnt++;
          }
        }
      }
      if (K == cnt)
      {
        ans++;
      }
    }
  }

  cout << ans << endl;
}
