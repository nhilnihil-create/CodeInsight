#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   vector<double> a(n);
   for(int i = 0; i < n; i++) {
       cin >> a[i];
   }
   sort(a.begin(), a.end());
   double ans = a[0];
   for(int i = 1; i < n; i++) {
       ans = (ans + (double) a[i]) / 2.0;
   }
   cout << fixed << setprecision(20) << ans << endl;
}