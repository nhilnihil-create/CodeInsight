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


int main()
{
    ll N, M; cin >> N >> M;
    vvll v(1e5+1);
    rep(i, N) {
        ll a, b; cin >> a >> b;
        v[a].push_back(b);
    }

    priority_queue<ll> que;
    ll ans = 0;
    for (int i = 1; i <= M; i++) {
        for (ll x : v[i]) que.push(x);

        if (que.size()) ans += que.top(), que.pop();
    }
    cout << ans << endl;
    return 0;
}