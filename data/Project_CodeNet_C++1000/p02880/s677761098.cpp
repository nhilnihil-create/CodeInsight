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
     for (int i = 1; i <= 9; ++i)
          for (int j = i; j <= 9; ++j)
               if (i * j == n)
               {
                    cout << "Yes\n";
                    return 0;
               }
     cout << "No\n";
     return 0;
}