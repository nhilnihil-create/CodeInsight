#include <bits/stdc++.h>
#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;

int main(void)
{
    ll N, Q;
    cin >> N >> Q;
    vector<vector<ll>> G(N);
    vector<ll> value(N);
    rep(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, Q)
    {
        ll p, x;cin >> p >> x;p--;
        value[p] += x;
    }

    auto solve = [&](auto solve, ll n, ll p) -> void {
        for (auto v : G[n])
            if (v != p)
            {
               value[v] += value[n];
                solve(solve, v, n);
            }
        return;
    };

    solve(solve, 0, -1);
    rep(i, N)
    {
        if (i > 0)
            cout << " ";
        cout << value[i];
    }
    cout << endl;
}