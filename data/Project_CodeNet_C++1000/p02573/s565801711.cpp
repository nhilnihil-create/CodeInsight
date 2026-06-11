#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll INF = 1e18;
const int mod = 1e9+7;
const int MAX = 1e6;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visit[MAX]; // 訪問の有無

struct unionfind {
    vector<int> par; // 各要素の根
    // vi size; // 自分以下の子の数(根の場合は集合の要素数)
    vector<bool> closed;
    unionfind(int n) {
        par.resize(n, -1);
        // size.resize(n, 1);
        closed.resize(n, false);
        // rep(i, n) {
        //     par[i] = i;
        // }
    }
    int root(int x) { // 要素xの根を返す
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) { // 要素xとyを同一の集合(根)に結合
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        closed[x] = closed[x] | closed[y];
    }
    bool same(int x, int y) { // 要素xとyが同一の集合に属するか判定
        return root(x) == root(y);
    }
    int size(int x) {
        return -par[root(x)];
    }
};

int n, m;

int main() {
    cin >> n >> m;
    unionfind f(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        f.unite(a, b);
    }
    int ans = 0;
    rep(i, n) {
        ans = max(ans, f.size(i));
    }
    cout << ans << "\n";
}