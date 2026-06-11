
#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
 
struct Edge {
    long long to;
};
using Graph = vector<vector<Edge>>;
 
int encode(int i, int j) {
    if (i < j) swap(i, j);
    return i * (i - 1) / 2 + j + 1;
}
 
int seen[2000000];  // 1:現在探索中のパスで行きがけ 2:探索後の頂点
int d[2000000];     // d[i]:= 始点から i への距離
int dfs(const Graph &G, int now) {
    if (seen[now] == 2) return d[now];
    seen[now] = 1;
    for (auto e : G[now]) {
        if (seen[e.to] == 1) {  // 閉路を検出
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[now], dfs(G, e.to) + 1);
    }
    seen[now] = 2;
    return d[now];
}
 
int main() {
    long long N;
    cin >> N;
    Graph G(N * (N - 1) / 2 + 1);
    FOR(i, 0, N) {
        int now = 0;
        LOOP(N - 1) {
            int j;
            cin >> j;
            j--;
            int next = encode(i, j);
            G[now].push_back({next});
            now = next;
        }
    }
 
    cout << dfs(G, 0) << endl;
    return 0;
}