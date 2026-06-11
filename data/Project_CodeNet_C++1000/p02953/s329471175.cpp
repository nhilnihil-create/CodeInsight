#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42

using ll = long long;

void solve() {
   int n;
   cin >> n;
   vector <int> h(n);
   for(int i = 0; i < n; i++) {
      cin >> h[i];
   }
   h[0]--;
   for(int i = 1; i < n; i++) {
      if(h[i - 1] < h[i]) {
         h[i]--;
      }
      if(h[i] < h[i - 1]) {
         cout << "No" << endl;
         return;
      }
   }
   cout << "Yes" << endl;
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
