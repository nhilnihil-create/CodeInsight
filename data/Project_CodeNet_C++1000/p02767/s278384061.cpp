#include "bits/stdc++.h"
using ll = long long;
using namespace std;

int get(vector <int> &v, int d) {
   int ans = 0;
   for(auto &e: v) {
      ans += (e - d) * (e - d);
   }
   return ans;
}

void solve() {
   int n;
   cin >> n;
   vector <int> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
   }
   int sum = accumulate(v.begin(), v.end(), 0);
   double avg = sum / n;
   int nearest = (int) avg;

   int ans = INT_MAX;
   for(int i = nearest; i <= nearest + 1; i++) {
      ans = min(ans, get(v, i));
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
