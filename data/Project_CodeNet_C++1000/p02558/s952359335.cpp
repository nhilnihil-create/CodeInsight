#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

class UnionFind {
private:
    vector<int> parent_;
    vector<int> node_rank_;
    vector<int> sizes_;
public:
    UnionFind(int node_num):
        parent_(vector<int>(node_num)), node_rank_(vector<int>(node_num)), sizes_(vector<int>(node_num)) {
        for (int i = 0; i < node_num; ++i) {
            parent_[i] = i;
            node_rank_[i] = 0;
            sizes_[i] = 1;
        }
    }
    int getRoot(int u) {
        return parent_[u] == u ? u : parent_[u] = getRoot(parent_[u]);
    }
    bool isSame(int u, int v) {
        return getRoot(u) == getRoot(v);
    }
    void unite(int u, int v) {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) return;
        if (node_rank_[u] < node_rank_[v]) {
            parent_[u] = v;
            sizes_[v] += sizes_[u];
        }
        else {
            parent_[v] = u;
            sizes_[u] += sizes_[v];
            if (node_rank_[u] == node_rank_[v]) {
                node_rank_[u]++;
            }
        }
    }
    int getSize(int u) {
        return sizes_[getRoot(u)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    int t, u, v;
    rep(i, 0, Q) {
        cin >> t >> u >> v;
        if (t) {
            if (uf.isSame(u, v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            uf.unite(u, v);
        }
    }
    return 0;
}