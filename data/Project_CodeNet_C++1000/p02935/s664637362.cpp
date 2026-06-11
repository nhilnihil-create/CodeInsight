#include "bits/stdc++.h"
using ll = long long;
using namespace std;



void solve() {
   int n;
   cin >> n;
   vector <int> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
   }
   sort(v.begin(), v.end());

   double ans = 0;
   long long f = 2;
   for(int i = n - 1; i >= 0; i--) {
      if(i == 0) f /= 2;
      ans += v[i] / (double) f;
      f *= 2;
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
