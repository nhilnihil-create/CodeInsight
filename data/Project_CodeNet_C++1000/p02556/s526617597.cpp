#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   long long zmi = 1e18, wmi = 1e18;
   long long zma = -1e18, wma = -1e18;
   for(int i = 0; i < n; i++) {
       long long foo, bar;
       cin >> foo >> bar;
       zmi = min(zmi, foo + bar);
       zma = max(zma, foo + bar);
       wmi = min(wmi, foo - bar);
       wma = max(wma, foo - bar);
   }
   long long ans = max(zma - zmi, wma - wmi);
   cout << ans << endl;
}