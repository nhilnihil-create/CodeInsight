#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct UnionFind{
    vector<int> par; // par[i]:iの親の番号
    
    UnionFind(int N) : par(N) {
        for(int i=0; i<N; i++) par[i] = i;
    }
    
    int root(int x){ // xが属する木の根
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){ // xとyの木を併合
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[min(rx,ry)] = max(rx,ry);
    }
    
    bool same(int x, int y){ // xとyが同じ木に属するかどうか
        return root(x) == root(y);
    }
};

int main(void){
    ll N; cin >> N;
    vector<ll> x(N), y(N); REP(i,N) cin >> x[i] >> y[i];

    ll ans = LL_INF;
    REP(i,N)REP(j,N){
        ll p = x[i]-x[j], q = y[i] - y[j];
        UnionFind uf(N);
        REP(s,N)REP(t,N){
            if(x[s]-x[t]==p && y[s]-y[t]==q) uf.unite(s,t);
        }
        set<int> s; REP(i,N) s.insert(uf.root(i));
        chmin(ans, (ll)s.size());
    }
    
    cout << ans << endl;
    return 0;
}