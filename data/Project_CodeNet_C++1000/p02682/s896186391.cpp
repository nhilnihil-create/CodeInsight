#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
ll a, b, c, k;

int main()
{
    cin >> a >> b >> c >> k;

    ll ans = 0;
    if (k >= a)
    {
        ans += a;
        k -= a;
    }
    else
    {
        ans += k;
        k = 0;
    }

    // cout << k << endl;
    if (k >= b)
    {
        k -= b;
    }
    else
    {
        k = 0;
    }
    // cout << k << endl;
    if (k >= c)
    {
        ans -= c;
    }
    else
    {
        ans -= k;
        k = 0;
    }
    cout << ans << endl;
    return 0;
}
