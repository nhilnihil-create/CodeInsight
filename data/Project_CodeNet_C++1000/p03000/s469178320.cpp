#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n + 1);
    v[0] = 0;
    for (ll i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        v[i + 1] = v[i] + tmp;
    }
    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        if (v[i] <= x)
            ans++;
    }
    cout << ans << endl;
}
