#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (llong (Itr) = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

#include <iostream>
#include <vector>
using namespace std;
using llong = long long;

llong n, q;
vector<vector<int>> g;
vector<llong> cnt;
vector<llong> ans;

void dfs(int u, int par, llong c) {
    c += cnt[u];
    ans[u] = c;

    for (auto vs:g[u]) {
        if (vs == par) continue;
        dfs(vs, u, c);
    }
}

int main() {
    cin >> n >> q;

    g.resize(n + 1);
    cnt.resize(n + 1);
    ans.resize(n + 1);
    repeat(i, n - 1) {
        llong a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    repeat(i, q) {
        llong p, x;
        cin >> p >> x;
        cnt[p] += x;
    }

    dfs(1, 0, 0);

    repeat(i, 1, n + 1) {
        cout << ans[i] << ' ';
    }

    return 0;
};
