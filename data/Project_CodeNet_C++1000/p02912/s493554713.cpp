#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// #include "debug.h"
#define debug(...) 42

void solve() {
   int n, k, x;
   cin >> n >> k;
   set <array <int, 2> > s;
   for(int i = 0; i < n; i++) {
      cin >> x;
      s.insert({x, i});
   }

   while(k--) {
      auto t = *s.rbegin();
      s.erase(t);
      s.insert({t[0] / 2, t[1]});
   }

   ll ans = 0;
   for(auto t: s) {
      ans += t[0];
   }
   cout << ans << endl;
} 

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   }
   return 0;
}
