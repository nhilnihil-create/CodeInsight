#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    deque<ll> a(n + 1), b(n);
    rep(i, n + 1)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    ll ans = 0;
    rep(i, n)
    {

        if (b[i] >= a[i])
        {
            ans += a[i];
            b[i] -= a[i];
            a[i] = 0;
        }
        else
        {
            ans += b[i];
            a[i] -= b[i];
            b[i] = 0;
        }
        if (b[i] >= a[i + 1])
        {
            ans += a[i + 1];
            b[i] -= a[i + 1];
            a[i + 1] = 0;
        }
        else
        {
            ans += b[i];
            a[i + 1] -= b[i];
            b[i] = 0;
        }
        // cout << a[i] << "," << b[i] << endl;
    }
    cout << ans << endl;

    return 0;
}
