#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
   ll a, b, c, k;
   cin >> a >> b >> c >> k;
   while (b <= a) {
      b *= 2;
      k--;
   }
   while (c <= b) {
      c *= 2;
      k--;
   }
   cout << (k >= 0 ? "Yes" : "No") << '\n';
   return 0;
}