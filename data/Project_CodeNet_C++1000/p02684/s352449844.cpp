#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
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

ll const MAX_V = 200005;

// 辺に属性がある場合
// 頂点toへのコストcostの辺
struct edge {
    ll to, cost;
};
vector<edge> G[MAX_V];

int main() {
    INIT;
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    for (ll i = 0; i < N; i++) {
        // sからtへの辺を張る
        A[i]--;
        edge et = {A[i], 1};
        G[i].push_back(et);

        // // 無向グラフの場合はさらにtにsへの辺を張る
        // edge es = {i, 1};
        // G[A[i]].push_back(es);
    }

    vector<ll> visited(N + 5, -1);
    ll nv = 0;
    ll first_visit = -1;
    ll loop_visit, loop_v;

    rep(i, K) {
        if (visited[nv] > 0) {
            first_visit = visited[nv];
            loop_visit = i - first_visit;
            loop_v = nv;
            break;
        }
        visited[nv] = i;
        nv = G[nv][0].to;
    }

    if (first_visit == -1) {
        cout << nv + 1 << endl;
        return 0;
    }

    // rep(i, N) { cout << visited[i] << " "; }
    // cout << endl;

    rep(i, N) { visited[i] -= first_visit; }

    // rep(i, N) { cout << visited[i] << " "; }
    // cout << endl;

    ll loop_num = (K - first_visit) / loop_visit;
    ll last_k = loop_num * loop_visit + first_visit;

    // cout << "loop_v: " << loop_v << ", loop_visit:" << loop_visit << ", "
    //      << K - last_k << endl;

    rep(i, N) {
        if (visited[i] == K - last_k) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    // nv = loop_v;
    // reps(i, last_k, K) { nv = G[nv][0].to; }

    // cout << nv + 1 << endl;

    return 0;
}