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

class UnionFind {
    public:
        UnionFind(){}
        UnionFind(int size) { Init(size); }
        // size: Union-Find で扱いたい要素の数
        void Init(int size) { m_Data.assign(size, -1); }

        // x と y の属する集合を併合
        // 既に一緒な集合内にいるなら false を
        // 新たに併合されたなら true を返す
        bool Unite(int x, int y) {
            x = Find(x), y = Find(y);
            if(x == y) { return (false); }
            if(m_Data[x] > m_Data[y]) { swap(x, y); }
            m_Data[x] += m_Data[y];
            m_Data[y] = x;
            return (true);
        }

        // 要素 k が属する集合の根を返す
        int Find(int k) {
            if(m_Data[k] < 0) { return (k); }
            return (m_Data[k] = Find(m_Data[k]));
        }

        // 要素 k と同じ集合の要素数を返す
        int Size(int k) { return (-m_Data[Find(k)]); }

        // 要素のうち独立しているグループの数 O(NlogN)
        int GetGroupNum() {
            map<int, bool> groups;
            for(int i = 0; i < m_Data.size(); ++i) { groups[Find(i)] = true; }
            return static_cast<int>(groups.size());
        }

    private:
        vector<int> m_Data;
};

signed main() {
    IOS;

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    REP(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            uf.Unite(u, v);
        }
        else {
            if(uf.Find(u) == uf.Find(v)) {
                print(1);
            }
            else {
                print(0);
            }
        }
    }

    return 0;
}
