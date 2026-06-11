#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

ll n, k;

vector<ll> vis(300000, -1);

int main()
{
    cin >> n >> k;
    vector<ll> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll next = 1, unit;
    vis[next] = 0;
    for (ll i = 1; i <= k; i++)
    {
        next = a[next];

        if (vis[next] != -1)
        {
            unit = i - vis[next];
            break;
        }
        else
        {
            vis[next] = i;
        }
    }

    if (unit)
    {
        ll c = (k - vis[next]) / unit;

        for (ll i = vis[next] + c * unit + 1; i <= k; i++)
            next = a[next];
    }

    cout << next << endl;
}