#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, a[300000], ans = 0, count = 1;
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        if (a[i] == count)
        {
            count++;
        }
        else
        {
            ans++;
        }
    }
    if (ans == n)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
