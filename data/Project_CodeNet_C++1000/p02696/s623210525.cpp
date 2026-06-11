#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    if (n < b)
    {
        //ans = floor(a * n / b);
        ans = a * n / b;
        ans -= a * (n / b);
    }
    else
    {
        n = b - 1;
        //ans = floor(a * (n / b));
        ans = a * n / b;
        ans -= a * (n / b);
    }
    cout << ans;
}