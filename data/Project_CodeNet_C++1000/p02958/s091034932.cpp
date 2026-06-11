#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    ll n, a, b;
    cin >> n;
    ll p[n];
    rep(i, n) cin >> p[i];
    rep(i, n - 2)
    {
        if (p[i] > p[i + 1])
        {
            for (ll j = i + 1; j < n - 1; j++)
            {
                if (p[j] > p[j + 1])
                {
                    ll tmp = p[i];
                    p[i] = p[j + 1];
                    p[j + 1] = tmp;
                }
            }
        }
    }
    rep(i, n - 1)
    {
        if (p[i] > p[i + 1])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    // rep(i, n) cout << p[i];
    cout << "YES" << endl;
    return 0;
}