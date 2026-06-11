#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector <int> v(n), vr(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
      vr[v[i] - 1] = i;
   }

   for(int i = 0; i < n; i++) {
      cout << vr[i] + 1 << " ";
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
