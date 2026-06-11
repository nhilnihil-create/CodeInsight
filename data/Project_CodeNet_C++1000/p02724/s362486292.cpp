#include <bits/stdc++.h>
using namespace std;

int main() {
   int a, b, c, d, ans;
   cin >> a;

   b = a / 500;
   ans = b * 1000;
   c = a % 500;
   d = c / 5;
   ans += d * 5;

   cout << ans << endl;
}