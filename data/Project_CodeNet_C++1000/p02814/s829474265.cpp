#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int bit2count(int a)
{
    for (int i = 0; i < 31; ++i)
        if (a & (1 << i))
            return i;
    return -1;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i], a[i] /= 2;
    int m2 = bit2count(a[0]);
    ll lcm = 1;
    rep(i, n)
    {
        if (bit2count(a[i]) != m2)
        {
            cout << 0 << endl;
            return 0;
        }
        lcm = lcm / __gcd(lcm, ll(a[i])) * ll(a[i]);
        if (lcm > m)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 0;
    for (ll i = lcm; i <= m; i += ll(2) * lcm)
        ++ans;
    cout << ans << endl;
}