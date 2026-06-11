#include "bits/stdc++.h"
using ll = long long;
using namespace std;

ll maxPow5(ll n) {
   ll ans = 0;
   ll cur = 1;
   while(cur * 5 <= n) {
      cur *= 5;
      ans += n / cur;
   }
   return ans;
}

void solve() {
   ll n;
   cin >> n;
   if(n % 2) {
      //7.5.3.1
      cout << 0 << endl;
   } else {
      //12.10.8
      cout << maxPow5(n / 2) << endl;
   }
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
