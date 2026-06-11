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
template <class T, class U> vector<U> make_vec(size_t a, U val) {
    return vector<U>(a, val);
}
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N, vector<int>());
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v);
    }
    int S, T;
    cin >> S >> T;
    S--, T--;
    auto dist = make_vec<size_t, size_t, int>(N, 3, INF);
    queue<pair<int, int>> que;
    que.push(MP(0, S));
    while(!que.empty()) {
        auto p = que.front();
        que.pop();
        int d = p.first;
        int v = p.second;
        for(auto nv : G[v]) {
            if(dist[nv][(d + 1) % 3] <= d + 1)
                continue;
            que.push(MP(d + 1, nv));
            dist[nv][(d + 1) % 3] = d + 1;
        }
    }
    cout << (dist[T][0] == INF ? -1 : dist[T][0] / 3) << endl;
    return 0;
}