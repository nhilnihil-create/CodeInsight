#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

ll dfs(const vvi& G, vb& seen, int curr, const int& k, int num) {
    seen[curr] = true;

    // この頂点に使える色数．
    ll ans = k - num;

    // この頂点に親がいるかどうか．
    int p = num >= 1 ? 1 : 0;

    int cnt = 0;
    for (int next : G[curr]) {
        if (seen[next]) { continue; }
        ans = (ans * dfs(G, seen, next, k, 1 + p + cnt++)) % MOD;
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vvi G(n);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    if (n == 1) {
        cout << k << endl;
        return 0;
    }

    // O(n)
    int s = 0;
    while (G[s].size() != 1) { ++s; }

    // O(n)
    vb seen(n, false);
    cout << dfs(G, seen, s, k, 0) << endl;

    return 0;
}