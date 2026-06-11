#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin >> n;
   for (int i = 1; i <= n; i++) {
      if (floor(i * 1.08) == n) {
         cout << i << '\n';
         return 0;
      }
   }
   cout << ":(" << '\n';
   return 0;
}