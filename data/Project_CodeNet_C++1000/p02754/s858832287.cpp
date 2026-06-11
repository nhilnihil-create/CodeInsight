   #include "bits/stdc++.h"
   using ll = long long;
   using namespace std;

   void solve() {
      ll n, a, b;
      cin >> n >> a >> b;
      ll ans = (n / (a + b)) * a;
      n -= (n / (a + b)) * (a + b);
      ans += min(n, a);
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
