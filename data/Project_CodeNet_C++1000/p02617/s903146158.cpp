#include <bits/stdc++.h>

using namespace std;
#define _rep(n, a, b) for (ll n = (a); n <= (b); ++n)
#define _rev(n, a, b) for (ll n = (a); n >= (b); --n)
#define _for(n, a, b) for (ll n = (a); n < (b); ++n)
#define _rof(n, a, b) for (ll n = (a); n > (b); --n)
#define oo 0x3f3f3f3f3f3f
#define ll long long
#define db long double
#define eps 1e-3
#define bin(x) cout << bitset<10>(x) << endl;
#define what_is(x) cerr << #x << " is " << x << endl
#define met(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pdd pair<db, db>
#define endl "\n"
const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 10;
deque<ll> a;
db posd[maxn], negd[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll all = 0;
    _rep(i, 1, n) {
        all += (i + 1) * i / 2;
    }

    _rep(i, 1, n - 1) {
        ll u, v;
        cin >> u >> v;
        if (u > v)swap(u, v);
        all -= u * (n - v + 1LL);
    }
    cout << all << endl;
}