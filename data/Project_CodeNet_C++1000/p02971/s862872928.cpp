#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n, greater<>());
    rep(i, n)
    {
        if (a[i] == b[0])
            cout << b[1] << endl;
        else
            cout << b[0] << endl;
    }
    return 0;
}