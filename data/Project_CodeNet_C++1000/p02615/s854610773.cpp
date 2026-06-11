#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
   freopen("inp.txt", "r", stdin);      freopen("outp.txt", "w", stdout);
#endif
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   int n;
   cin >> n;
   vector <int> a(n);
   for (auto &i : a) {
      cin >> i;
   }
   sort(a.rbegin(), a.rend());

   ll ans = a[0];
   for (int i = 1; i < n / 2; i++)
      ans += 2 * a[i];
   if (n % 2)
      ans += a[n / 2];

   cout << ans << '\n';

   return 0;
}