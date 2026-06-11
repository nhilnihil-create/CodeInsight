#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a;
    for (ll c = 1; c <= 50000; c++)
    {
        ll d = (108 * c) / 100;
        if (d == a) cout << c, exit(0);
    }
    cout << ":(";
}
