#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main()
{
  while (true)
  {
    int H;
    cin >> H;
    if (H == 0)
    {
      return 0;
    }
    vector<vector<int>> mp(5, vector<int>(H * 2, -1));
    for (int i = 0; i < H; ++i)
    {
      for (int j = 0; j < 5; ++j)
      {
        cin >> mp.at(j).at(H - 1  - i);
      }
    }
    int ans = 0;
    while (true)
    {
      bool didnt_erase = true;
      for (int i = H - 1; i >= 0; --i)
      {
        int cnt = 0;
        int now = - 1;
        for (int j = 0; j < 5; ++j)
        {
          if (mp.at(j).at(i) == -1)
          {
            if (cnt > 2)
            {
              ans += cnt * mp.at(j - 1).at(i);
              // cout << cnt * mp.at(j - 1).at(i) << endl;
              for (int k = 0; k < cnt; ++k)
              {
                mp.at(j - k - 1).erase(mp.at(j - k - 1).begin() + i);
              }
              didnt_erase = false;
            }
            now = -1;
            cnt = 0;
            continue;
          }
          else if (now == mp.at(j).at(i))
          {
            cnt += 1;
          }
          else
          {
            if (cnt > 2)
            {
              ans += cnt * mp.at(j - 1).at(i);
              // cout << cnt * mp.at(j - 1).at(i) << endl;
              for (int k = 0; k < cnt; ++k)
              {
                mp.at(j - k - 1).erase(mp.at(j - k - 1).begin() + i);
              }
              didnt_erase = false;
            }
            cnt = 1;
            now = mp.at(j).at(i);
          }
        }
        if (cnt > 2)
        {
          ans += cnt * mp.at(4).at(i);
          // cout << cnt * mp.at(4).at(i) << endl;
          for (int k = 0; k < cnt; ++k)
          {
            mp.at(4 - k).erase(mp.at(4 - k).begin() + i);
          }
          didnt_erase = false;
        }
      }
      if (didnt_erase)
      {
        break;
      }
    }
    // for (int i = 0; i < mp.size(); ++i)
    // {
    //   for (int j = 0; j < mp.at(i).size(); ++j)
    //   {
    //     cout << mp.at(i).at(j);
    //   }
    //   cout << endl;
    // }
    cout << ans << endl;
  }
}

