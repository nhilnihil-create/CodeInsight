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

ll N, K;
void dfs(int v, int p, ll k, ll &res, vector<vector<int>> &G) {
    res *= k;
    res %= MOD;
    int cs = G[v].size();
    int m = (p == -1 ? 1 : 2);
    for(auto nv : G[v]) {
        if(nv == p)
            continue;
        dfs(nv, v, K - m, res, G);
        m++;
    }
}

int main() {
    cin >> N >> K;
    vector<vector<int>> G(N, vector<int>());
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    ll res = 1;
    dfs(0, -1, K, res, G);
    cout << res << endl;
    return 0;
}