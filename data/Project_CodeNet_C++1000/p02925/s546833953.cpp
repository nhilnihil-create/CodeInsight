#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

struct edge {
    ll to, cost;
};
typedef pair<ll, ll> P;

vector<vector<edge>> G;
vec seen;
vec d;

ll dfs (ll v) {
    if (seen[v] == 2) return d[v];
    seen[v] = 1;
    d[v] = 1;
    for (auto e : G[v]) {
        ll f = e.to;
        ll g = e.cost;
        if (seen[f] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[v], dfs(f) + g);
    }
    seen[v] = 2;
    return d[v];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    mat A(N, vec(N-1));
    Rep (i, N) {
        Rep (j, N-1) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    mat id(N, vec(N));


    ll v = N*(N-1)/2;
    ll tmp = 0;
    Rep (i, N) {
        for (ll j = i+1; j < N; j++) {
            id[i][j] = tmp;
            id[j][i] = tmp++;
        }
    }

    G.assign(v, vector<edge>());
    Rep (i, N) {
        Rep (j, N-2) {
            G[id[i][A[i][j]]].push_back({id[i][A[i][j+1]], 1});
        }
    }

    seen.assign(v, 0);
    d.assign(v, 0);

    ll ans = 0;
    Rep (i, v) {
        ll ret = dfs(i);
        chmax(ans, ret);
    }
    cout << ans << endl;

}