//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <complex>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
	return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
	auto inner = make_vec_nd(init, rest...);
	return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

ll N;
vector<vector<ll>> tree;
unordered_map<ll, unordered_map<ll, ll>> to_edge_idx;

void calc_ans(ll now, ll avoid, vector<bool>& visited, vector<ll>& ans) {
    visited[now] = true;
    ll col = 0;
    for (ll to : tree[now]) {
        if (visited[to]) {
            continue;
        }
        if (col == avoid) {
            col++;
        }
        ans[to_edge_idx[now][to]] = col;
        calc_ans(to, col, visited, ans);
        col++;
    }
}

int main() {
    cin >> N;
    tree.resize(N);
    rep(i,0,N-1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        to_edge_idx[a][b] = i;
        to_edge_idx[b][a] = i;
    }
    ll col_cnt = 0;
    rep(i,0,N) {
        col_cnt = max(col_cnt, (ll)tree[i].size());
    }
    cout << col_cnt << endl;
    vector<ll> ans(N-1);
    vector<bool> visited(N);
    calc_ans(0, -1, visited, ans);
    rep(i,0,N-1) {
        cout << ans[i] + 1 << endl;
    }
}
