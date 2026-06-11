#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42

using ll = long long;

void solve() {
   int n, k, s;
   cin >> n >> k >> s;

   vector <int> v(n, s);
   int def = 1e9;
   if(s > 1e5)
      def = 1;
   for(int i = k; i < n; i++) {
      v[i] = def;
   }

   for(int i = 0; i < n; i++) {
      cout << v[i] << " ";
   }
   cout << endl;
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
