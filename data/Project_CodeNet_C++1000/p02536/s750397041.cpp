#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

class UnionFind {
    private :
        std::vector<int> par;
        std::vector<int> sz;
    public :
        UnionFind(int n) {
            par.resize(n);
            for (int i=0; i<n; i++) par[i] = i;
            sz.assign(n, 1);
        }
        void unite(int x, int y) {
            const int x_par = find(x);
            const int y_par = find(y);
            if (x_par == y_par) return;

            if (sz[x_par] < sz[y_par]) {
                par[x_par] = y_par;
                sz[y_par] += sz[x_par];
            } else {
                par[y_par] = x_par;
                sz[x_par] += sz[y_par];
            }
        }
        int find(int x) {
            if (par[x] == x) return x;
            else return par[x] = find(par[x]);
        }
        bool same(int x, int y) { return find(x) == find(y); }
        int size(int x) { return sz[find(x)]; }
};

void solve() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    int ans = N-1;
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        if (!uf.same(a-1, b-1)) {
            --ans;
            uf.unite(a-1, b-1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
