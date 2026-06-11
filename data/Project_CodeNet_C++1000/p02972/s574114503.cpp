#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n, m = 0;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1, 0);
    rep1(i, n) cin >> a[i];

    for (ll i = n; i > 0; i--)
    {
        ll sum = 0;
        for (ll j = i; j <= n; j += i)
        {
            sum += b[j];
        }
        if (sum % 2 != a[i])
            b[i] = 1;
    }
    cout << accumulate(b.begin(), b.end(), 0) << endl;
    rep1(i, n)
    {
        if (b[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}