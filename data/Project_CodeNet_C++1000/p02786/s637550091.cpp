#include "bits/stdc++.h"
using ll = long long;
using namespace std;

ll get(ll h) {
   if(h == 1) return 1;
   return 2 * get(h / 2) + 1;
}
void solve() {
   ll h;
   cin >> h;
   cout << get(h) << endl;
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
