#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
#define all(x) x.begin(), x.end()

void solve() {
   ll a, b, c, d;
   cin >> a >> b >> c >> d;
   cout << max({b * d, a * c, a * d, c * b}) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("C:\\inp.txt", "r", stdin);      freopen("C:\\outp.txt", "w", stdout);
#endif
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);
   solve();

   return 0;
}