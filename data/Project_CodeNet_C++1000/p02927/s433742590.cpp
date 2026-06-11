#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int M, D, ans = 0;

   cin >> M >> D;

   for (int d = 10; d <= D; d++) {
     for (int m = 1; m <= M; m++) {
        if (d % 10 > 1 && d / 10 > 1 && (d % 10) * (d / 10) == m) ans++;
     }
   }
   cout << ans << endl;
 }
