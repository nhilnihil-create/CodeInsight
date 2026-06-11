#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// --------------------------------------------------------
#define FOR(i,l,r) for (int i = (l); i < (r); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define MIN(c) *min_element(ALL(c))
#define MAX(c) *max_element(ALL(c))
#define SUM(c) accumulate(ALL(c), 0)
#define SUMLL(c) accumulate(ALL(c), 0LL)
#define SZ(c) ((int)(c).size())
#define debug(x) cerr << #x << " = " << (x) << '\n';
using P = pair<int,int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const int INF = 1 << 30;
// const ll INF = 1LL << 62;
// --------------------------------------------------------


/**
 * @brief Union Find class.
 * 
 * @details "Path compression" and "Union by rank" are used.
 * @see <https://en.wikipedia.org/wiki/Disjoint-set_data_structure>
 */
class UnionFind {
    public:
        /**
         * @brief Construct a new Union Find object.
         * 
         * @param N Number of node.
         */
        UnionFind(int N) {
            _N = N;
            _make_set();
        }

        int find(int x) {
            if (_parent[x] != x) {
                _parent[x] = find(_parent[x]);
            }
            return _parent[x];
        }

        void unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);

            if (x_root == y_root) return;

            int x_rank = _rank[x_root];
            int y_rank = _rank[y_root];
            if (x_rank > y_rank) {
                _parent[y_root] = x_root;
                _size[x_root] += _size[y_root];
            } else if (x_rank < y_rank) {
                _parent[x_root] = y_root;
                _size[y_root] += _size[x_root];
            } else {
                _parent[y_root] = x_root;
                _rank[x_root] += 1;
                _size[x_root] += _size[y_root];
            }
        }

        bool same_set(int x, int y) { return find(x) == find(y); }

        int size(int x) { return _size[find(x)]; }


    private:
        int _N;
        vector<int> _parent, _rank, _size;

        void _make_set() {
            _parent = vector<int>(_N + 1);
            iota(_parent.begin(), _parent.end(), 0);
            _rank = vector<int>(_N + 1, 0);
            _size = vector<int>(_N + 1, 1);
        }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, Q; cin >> N >> Q;
    auto uf = UnionFind(N);
    REP(_, Q) {
        int t, u, v; cin >> t >> u >> v;
        u++; v++;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            cout << (uf.same_set(u, v) ? 1 : 0) << '\n';
        }
    }

    return 0;
}
