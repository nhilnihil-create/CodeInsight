#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int l, r;
   cin >> l >> r;
   if(r - l >= 2019) {
       cout << 0 << endl;
       return 0;
   } else {
       long long ans = 2018;
       for(int i = l; i < r; i++) {
           for(int j = i + 1; j <= r; j++) {
               ans = min(ans, (long long) i * (long long) j % 2019);
           }
       }
       cout << ans << endl;
   }
}