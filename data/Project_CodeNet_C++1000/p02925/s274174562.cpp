#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

ll const MAX_V = 500005;

struct edge {
    ll to, cost;
};
vector<edge> G[MAX_V];
vector<vector<ll>> ids(1005, vector<ll>(1005, 0));

vector<ll> seen;
vector<ll> d;
bool flg;

ll dfs(int v, int p) {
    if (seen[v] == 2) return d[v];
    seen[v] = 1;

    for (auto nv : G[v]) {
        if (nv.to == p) continue;
        // cout << v << "->" << nv.to << ": " << seen[nv.to] << endl;

        if (seen[nv.to] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[v], dfs(nv.to, v) + 1);
    }

    seen[v] = 2;

    return d[v];
}

int main() {
    INIT;

    ll N;
    cin >> N;

    ll v = 1;
    rep(i, N) {
        reps(j, i + 1, N) {
            ids[i][j] = v;
            ids[j][i] = v;
            v++;
        }
    }

    rep(i, N) {
        ll now = 0;

        rep(j, N - 1) {
            ll s;
            cin >> s;
            s--;

            ll next = ids[i][s];
            edge et = {next, 1};

            G[now].push_back(et);
            now = next;
        }
    }

    seen.assign(N * (N - 1) / 2 + 5, 0);
    d.assign(N * (N - 1) / 2 + 5, 0);

    // rep(i, N * (N - 1) / 2) {
    //     cout << i << ": ";
    //     for (auto nv : G[i]) {
    //         cout << nv.to << " ";
    //     }
    //     cout << endl;
    // }

    cout << dfs(0, -1) << endl;

    return 0;
}