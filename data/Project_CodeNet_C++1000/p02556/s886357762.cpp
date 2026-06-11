#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll mn = 1e18, mnn = 1e18;
    ll mx = -1e18, mxx = -1e18;
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        mn = min(mn, x + y);
        mx = max(mx, x + y);
        mnn = min(mnn, x - y);
        mxx = max(mxx, x - y);
    }
    cout << max(mx - mn, mxx - mnn);
}