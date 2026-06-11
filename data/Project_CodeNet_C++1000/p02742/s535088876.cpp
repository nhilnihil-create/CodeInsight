#include "bits/stdc++.h"
using ll = long long;
using namespace std;


void solve() {
   ll n, m;
   cin >> n >> m;
   if(n == 1 || m == 1) {
      cout << 1 << endl;
      return;
   }
   ll ans = (n * m) / 2;

   if((n % 2 == 1) && (m % 2 == 1)) {
      ans++;
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
