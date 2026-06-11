#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

void dfs(int v, int p, int now, vector<vector<int>> &G, vector<int> &counter,
         vector<int> &res) {
    now += counter[v];
    res[v] = now;
    for(auto nv : G[v]) {
        if(nv == p)
            continue;
        dfs(nv, v, now, G, counter, res);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N, vector<int>());
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<int> counter(N);
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        p--;
        counter[p] += x;
    }

    vector<int> res(N);
    dfs(0, -1, 0, G, counter, res);
    rep(i, N) { cout << res[i] << (i == N - 1 ? '\n' : ' '); }
    return 0;
}