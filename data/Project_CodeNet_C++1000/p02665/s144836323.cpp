#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   long long n;
   cin >> n;
   vector<long long> a(n+1);
   for (int i = 0; i < n + 1; i++) {
      cin >> a[i];
   }

   if (n == 0 && a[0] == 1) {
      cout << 1 << '\n';
      return 0;
   }
   else if (n == 0 && a[0] != 1) {
      cout << -1 << '\n';
      return 0;
   }
   else if (a[0] != 0) {
      cout << -1 << '\n';
      return 0;
   }

   vector<pair<long long,long long>> b(n+1);
   b[n].first = a[n];
   b[n].second = a[n];
   for (int i = n - 1; i >= 0; i--) {
      b[i].first = (b[i+1].first + 1) / 2 + a[i];
      b[i].second = b[i+1].second + a[i];
   }

   if (b[0].first <= 1 && 1 <= b[0].second);
   else {
      cout << -1 << '\n';
      return 0;
   }
   
   long long ans = 1;
   vector<long long> c(n);
   c[0] = 1;
   for (int i = 1; i < n; i++) {
      c[i] = min((c[i-1] - a[i-1]) * 2, b[i].second);
      ans += c[i];
   }
   ans += a[n];
   cout << ans << '\n';
   return 0;
}