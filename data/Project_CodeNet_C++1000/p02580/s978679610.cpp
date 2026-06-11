#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
using ll = long long;
#define int ll
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
#define IOS\
    ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SORT(name) sort(name.begin(), name.end())
#define RSORT(name)\
    SORT(name);\
    reverse(all(name));
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
template <class T> inline void print(T x){ cout << x << '\n';}
template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
#pragma endregion

#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const int MOD = 1000000007;
const int MAX_N = 100010;

int H, W, M;
map<int, int> row, col;
set<pii> exist;

signed main() {
    IOS;

    cin >> H >> W >> M;
    int max_h = 0, max_w = 0;
    REP(i, M) {
        int h, w;
        cin >> h >> w;
        row[h]++;
        col[w]++;
        exist.insert(mp(h, w));
        chmax(max_h, row[h]);
        chmax(max_w, col[w]);
    }
    V<> row_v, col_v;   // 最大値をもつ行と列
    for(auto b : row) {
        if(b.second == max_h) {
            row_v.pb(b.first);
        }
    }
    for(auto c : col) {
        if(c.second == max_w) {
            col_v.pb(c.first);
        }
    }

    int ans = max_h + max_w - 1;
    REP(i, row_v.size()) {
        REP(j, col_v.size()) {
            auto it = exist.find(mp(row_v[i], col_v[j]));
            if(it == exist.end()) {
                print(max_h + max_w);
                return 0;
            }
        }
    }
    print(ans);

    return 0;
}
