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
     ll n;
     cin >> n;
     ll ans = 1;
     for (ll i = 1; i * i <= n; ++i)
          if (n % i == 0)
               ans = i;
     cout << (n / ans + ans - 2) << '\n';
     return 0;
}