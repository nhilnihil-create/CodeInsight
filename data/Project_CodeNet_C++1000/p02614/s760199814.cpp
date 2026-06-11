#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
using namespace std;

vector<string> v, t;

int main()
{
   int H, W, K;

   cin >> H >> W >> K;

   v.resize(H);

   for (int i = 0; i < H; i++)
   {
      cin >> v[i];
   }

   int ans = 0;
   for (int i = 0; i < (1 << H); i++)
   {
      
      for (int k = 0; k < (1 << W); k++)
      {
         t = v;
         for (int x = 0; x < H; x++)
         {
            for (int y = 0; y < W; y++)
            {
               if (((1 << x) & i) || ((1 << y) & k))
               {
                  t[x][y] = 'R';
               }
            }
         }

         int cnt = 0;
         for (int x = 0; x < H; x++)
         {
            for (int y = 0; y < W; y++)
            {
               if (t[x][y] == '#')
               {
                  cnt++;
               }
            }
         }

         /*
         for (int i = 0; i < H; i++)
         {
            cout << t[i] << "\n";
         }

         cout << cnt << "\n";
         */

         if (cnt == K)
         {
            ans++;
         }
      }
   }

   cout << ans;


   return 0;
}