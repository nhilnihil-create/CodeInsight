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
     string s;
     int n;
     cin >> n >> s;
     if (n < 3200)
          cout << "red";
     else
          cout << s;
     return 0;
}