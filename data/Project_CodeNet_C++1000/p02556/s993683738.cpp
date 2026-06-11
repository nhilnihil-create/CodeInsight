#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007

int main()
{
    ll n;
    cin >> n;
    ll zmi = 2e9, zma = -2e9, wmi = 2e9, wma = -2e9;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        zmi = min(zmi, x + y);
        zma = max(zma, x + y);
        wmi = min(wmi, x - y);
        wma = max(wma, x - y);
    }

    cout << max(zma - zmi, wma - wmi) << endl;

    return 0;
}