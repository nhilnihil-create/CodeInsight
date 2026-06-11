#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin >> n;
   vector<int> x(n + 1);
   int min_x = 101, max_x = 0;
   for(int i = 1; i <= n; i++)
   {
     cin >> x[i];
     min_x = min(min_x, x[i]);
     max_x = max(max_x, x[i]);
   }
   int best = 1e9;
   for(int p = min_x; p <= max_x; p++)
   {
      int cur_best = 0;
      for(int i = 1; i <= n; i++)
      {
         cur_best += (x[i] - p) * (x[i] - p);
      }
      best = min(best, cur_best);
   }
  
   cout << best << endl;
   return 0;
}
