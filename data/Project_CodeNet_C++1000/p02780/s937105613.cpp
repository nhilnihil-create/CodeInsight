#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n, k;
   cin >> n >> k;
   vector <double> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
      v[i] += 1;
      v[i] /= 2.0;
   }
   double sum = 0;
   for(int i = 0; i < k; i++) {
      sum += v[i];
   }
   double maxSum = sum;

   for(int i = k; i < n; i++) {
      sum = sum - v[i - k] + v[i];
      maxSum = max(maxSum, sum);
   }
   cout << fixed << setprecision(10) << maxSum << endl;

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
