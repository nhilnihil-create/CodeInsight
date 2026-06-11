#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> dist(n, -1);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    dist[0] = 0;
    ll before = 0;
    ll from = 0;
    ll loop = 0;
    while (1)
    {
        ++loop;
        ll to = a[from];
        if (dist[to] != -1)
        {
            before = dist[to];
            loop -= dist[to];
            from = to;
            break;
        }
        dist[to] = dist[from] + 1;
        from = to;
    }

    ll ans = 0;
    if (k >= before)
    {
        k = (k - before) % loop;
        ans = from;
    }
    while (k--)
        ans = a[ans];

    cout << ans + 1 << endl;
}