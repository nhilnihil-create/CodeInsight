#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000007
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define max(x) *max_element(all(x))
#define min(x) *min_element(all(x))

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> g(n);
    rep(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b), g[b].push_back(a);
    }
    map<ll, ll> mp;
    vector<ll> val(n, -1);
    rep(i, 0, q)
    {
        ll a, b;
        cin >> a >> b;
        --a;
        mp[a] += b;
    }
    queue<ll> que;
    que.push(0);
    val[0] = mp[0];
    while (!que.empty())
    {
        ll tmp = que.front();
        que.pop();
        for (auto i : g[tmp])
        {
            if (val[i] == -1)
                val[i] = val[tmp] + mp[i], que.push(i);
        }
    }
    rep(i, 0, n) cout << val[i] << endl;
}