#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define All(a) a.rbegin(), a.rend()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(10), cout << fixed
int main()
{
     ios;
     int n;
     cin >> n;
     double ans = 0, x = 1;
     for (int i = 0, a; i < n; ++i)
     {
          cin >> a;
          ans += x / a;
     }
     cout << x / ans << '\n';
     return 0;
}