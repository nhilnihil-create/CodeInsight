#include <bits/stdc++.h>
using namespace std;

#define ii pair <ll, ll>
#define ll long long
#define X first
#define Y second

const ll N = 3E5 + 10;

ll n, m;
ll a[N], Sum[N], d[N];

void Input()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) scanf("%lld", &a[i]);
}

bool check(ll mid, ll k)
{
    ll pos = upper_bound(a + 1, a + 1 + m, mid) - (a + 1);
    if (pos > m) pos = m;
    if (Sum[pos] / mid + (m - pos) >= k) return true;
    return false;
}

void Solve()
{
    for (ll i = 1; i <= n; i++) d[a[i]]++;
    for (ll i = 1; i <= n; i++) if (d[i] > 0) a[++m] = d[i];
    sort(a + 1, a + 1 + m);
    for (ll i = 1; i <= m; i++) Sum[i] = Sum[i - 1] + a[i];

    for (ll k = 1; k <= n; k++) {
        ll x;
        ll l = 1, r = 1e9;
        ll ans = 0;
        while (l <= r) {
            ll mid = l + r >> 1;
            if (check(mid, k)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        printf("%lld\n", ans);
    }
}

#define task "test"
int main()
{
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll testcase = 1;
    /// cin >> testcase;
    while (testcase--) {
        Input();
        Solve();
    }
}


