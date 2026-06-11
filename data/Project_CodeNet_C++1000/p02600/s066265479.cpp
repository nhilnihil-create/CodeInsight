#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   int x, y = 400, z = 0;
   cin >> x;
   while (y + 200 <= x) {
      y += 200;
      z++;
   }
   cout << 8 - z << '\n';

   return 0;
}