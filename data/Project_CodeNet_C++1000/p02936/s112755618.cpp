#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn =  2e5;
int n, q;
graph G(maxn);
vi res(maxn);
vi seen;

int dfs(int v, int t) {
    seen[v] = true;
    for(auto next_v : G[v]) {
        if (seen[next_v.to]) continue;
        res[next_v.to] += res[v];
        t = dfs(next_v.to, t+1);
    }
    t += 1;
    return t;
}

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n >> q;
    REP(i, n-1) {
        edge e;
        int s; cin >> s >> e.to;
        s--; e.to--;
        G[s].push_back(e);
        swap(s, e.to);
        G[s].push_back(e);
    }
    REP(i, n) res[i] = 0;

    REP(i, q) {
        int s, c; cin >> s >> c;
        s--;
        res[s] += c;
    }

    seen.assign(n, false);

    dfs(0, 0);

    REP(i, n) {
        cout << std::fixed << std::setprecision(10) << res[i];
        delim(i, n);
    }
}