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

vector<long long> v;

int main()
{
   int n;
   cin >> n;

   v.resize(n);

   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
   }

   sort(v.begin(), v.end(), [&](int a, int b)
   {
      return a > b;
   });

   long long ans = 0;
   int index = 0;
   for (int i = 1; i < n; i++)
   {
      //cout << v[index] << "\n";
      if (i == 1)
      {
         ans += v[index];
         index++;
      }
      else
      {
         ans += v[index];
         if (i & 1)
         {
            index++;
         }
      }
   }
   cout << ans;

   return 0;
}