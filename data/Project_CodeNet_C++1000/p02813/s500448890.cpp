#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector <int> a(n), b(n);

   for(int i = 0; i < n; i++) {
      cin >> a[i];
   }
   for(int i = 0; i < n; i++) {
      cin >> b[i];
   }

   if(a > b) swap(a, b);
   int ans = 0;
   do {
      if(a == b) break;
      ans++;
   } while(next_permutation(a.begin(), a.end()));
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
