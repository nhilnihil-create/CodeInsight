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
   for (auto &i: a)
      cin >> i;
   ll money = 1000;
   for (int i = 0; i < n - 1; i++) {
      ll stocks = 0;
      if (a[i] < a[i + 1])
         stocks = money / a[i];
      money += stocks * (a[i + 1] - a[i]);
   }
   cout << money << '\n';

   return 0;
}