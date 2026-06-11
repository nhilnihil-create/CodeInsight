#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAX { 100010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

vector<int> adj[MAX];
bitset<MAX> found;

ll dfs(ll u, ll n, ll K)
{
    ll res = 1;

    for (auto v : adj[u])
    {
        if (found[v])
            continue;

        found[v] = true;
        ll ways = (n * dfs(v, K - 2, K)) % MOD;
        res = (res * ways) % MOD;
        --n;
    }

    return res;
}

ll solve(ll K)
{
    found.reset();
    found[1] = true;

    ll ans = (K * dfs(1, K - 1, K)) % MOD;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    while (--N)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto ans = solve(K);

    cout << ans << '\n';

    return 0;
}
