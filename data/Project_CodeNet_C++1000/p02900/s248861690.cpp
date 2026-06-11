#include "bits/stdc++.h"
#define int ll

using namespace std;
using ll = long long;
// #include "debug.h"
#define debug(...) 42

void solve() {
   ll a, b;
   cin >> a >> b;
   ll g = __gcd(a, b);
   int cnt = 1;
   ll G = g;
   for(int i = 2; i * 1LL * i <= G; i++) {
      cnt += !(g % i);
      while(g % i == 0) {
         g /= i;
      }
   }
   cnt += g > 1;
   // debug(g, cnt);
   cout << cnt << endl;
} 

signed main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   }
   return 0;
}
