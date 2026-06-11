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



class SegmentTree {
    public:
        /**
         * @brief Construct a new Segment Tree object.
         * 
         * @param N Number of node.
         * @param init_v Initial value that does not affect _func.
         *               For example, specify INF when _func = min.
         * @param X Vector for initialization.
         */
        SegmentTree(int N, ll init_v, vector<ll> X) {
            _N = N;
            _init_v = init_v;
            _build(X);
        }

        /**
         * @brief Update the i-th node value to x.
         * 
         * @param i Index (1-based index).
         * @param x Update value.
         */
        void update(int i, ll x) {
            i += _N - 1;
            _node[i] += x;
            while (i > 1) {
                i >>= 1;
                _node[i] = _func(_node[i << 1], _node[i << 1 | 1]);
            }
        }

        /**
         * @brief Query for right half-open interval [l, r).
         * 
         * @param l Index (1-based index).
         * @param r Index (1-based index).
         * @return Result of the query.
         */
        ll query(int l, int r) {
            ll dst_l = _init_v;
            ll dst_r = _init_v;
            l += _N - 1;
            r += _N - 1;
            while (l < r) {
                if (l & 1) {
                    dst_l = _func(dst_l, _node[l]);
                    l++;
                }
                if (r & 1) {
                    r--;
                    dst_r = _func(_node[r], dst_r);
                }
                l >>= 1;
                r >>= 1;
            }
            return _func(dst_l, dst_r);
        }

    private:
        int _N;
        ll _init_v;
        vector<ll> _node;

        ll _func(ll x, ll y) {
            return x + y;
        }

        void _build(vector<ll> X) {
            // Initialize all nodes
            _node = vector<ll>(2 * _N, _init_v);  // 1-based index

            // Elementary intervals are stored
            for (int i = 0; i < _N; i++) {
                _node[i + _N] = X[i];
            }

            // The internal nodes correspond to intervals that are the union of elementary intervals
            for (int i = _N - 1; 0 < i; i--) {
                _node[i] = _func(_node[i << 1], _node[i << 1 | 1]);
            }
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);

    int N, Q; cin >> N >> Q;
    vector<ll> a(N); REP(i, N) cin >> a[i];

    auto st = SegmentTree(N, 0LL, a);

    REP(_, Q) {
        int q, l, r; cin >> q >> l >> r;
        if (q == 0) {
            l++;
            st.update(l, r);
        } else {
            l++; r++;
            cout << st.query(l, r) << '\n';
        }
    }

    return 0;
}
