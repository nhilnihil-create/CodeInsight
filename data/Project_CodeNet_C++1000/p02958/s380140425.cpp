#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int main()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; ++i)
        cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    ll ans = 0;
    for (ll i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
            ++ans;
    }
    if (ans > 2)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
