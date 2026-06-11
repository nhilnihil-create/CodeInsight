#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, Q;
    cin >> N >> Q;

    vec<vec<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    map<ll, ll> mp;
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        --p;
        mp[p] += x;
    }

    vec<ll> ans(N);
    function<void(int, int, ll)> dfs = [&](int i, int par, ll sm) {
        ans[i] = sm;
        for (auto e : G[i]) {
            if (e == par) continue;
            dfs(e, i, sm + mp[e]);
        }
    };

    dfs(0, -1, mp[0]);
    rep(i, N) {
        cout << ans[i] << ' ';
    }
}
