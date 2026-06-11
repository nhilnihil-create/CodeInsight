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

ll get_cnt(ll n) {
    ll cnt = 0;
    while (n % 2 == 0) cnt++, n /= 2;
    return cnt;
}

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
    vll a(N); rep(i, N) {
        ll num; cin >> num; a[i] = num / 2;
    }

    ll d = get_cnt(a[0]);
    rep(i, N) if (get_cnt(a[i]) != d) {cout << 0 << endl; return 0;}

    ll lcm = 1;
    rep(i, N) {
        lcm = lcm * a[i] / gcd(lcm, a[i]);
    }
    //cout << lcm << endl;

    cout << (M / lcm + 1) / 2 << endl;

    return 0;
}