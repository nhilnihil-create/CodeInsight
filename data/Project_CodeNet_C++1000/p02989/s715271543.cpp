#include "bits/stdc++.h"
using ll = long long;
using namespace std;


void solve() {
   int n;
   cin >> n;
   vector <int> v(n);
   for(auto &e: v) {
      cin >> e;
   }
   sort(v.begin(), v.end());
   int x = v.size() / 2;
   cout << v[x] - v[x - 1] << endl;
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
