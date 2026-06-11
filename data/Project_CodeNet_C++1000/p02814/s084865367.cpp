#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b) {
        ll x = a, y = b;
        a = y, b = x % y;
    }

    return a;
}

int main()
{
    ll N, M; cin >> N >> M;
    vll a(N);
    rep(i, N) {
        ll num; cin >> num; a[i] = num / 2;
    }

    while (a[0] % 2 == 0) {
        rep(i, N) {
            if (a[i] % 2) {cout << 0 << endl; return 0;}
            a[i] /= 2;
        }
        M /= 2;
    }

    rep(i, N) if (a[i] % 2 == 0) {cout << 0 << endl; return 0;}

    ll lcm = 1;
    rep(i, N) {
        lcm = lcm / gcd(lcm, a[i]) * a[i];
        if (lcm > M) {cout << 0 << endl; return 0;}
    }
    cout << (M / lcm + 1) / 2 << endl;

    return 0;
}