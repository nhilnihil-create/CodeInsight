#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);++i)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);--i)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
//constexpr long long MOD = 998244353LL;
using ld=long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, rev;
    long double cap;
	Edge(ll _to, long double _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, long double cap, bool revFlag, long double revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}


void solve(){
    ll n;
    cin>>n;
    vec<ll> c(n+1,0);//ai=jとなるiの数
    REP(i,n){
        ll a;
        cin>>a;
        c[a]++;
    }
    vec<ll> d(n+1,0);//ci=jとなるiの数
    REP(i,n+1) d[c[i]]++;

    vec<ll> sumkd(n+2,0),sumd(n+2,0);
    REP(i,n+1) sumkd[i+1] = sumkd[i]+i*d[i];
    rep(i,1,n+1) sumd[i+1] = sumd[i]+d[i];

    vec<ll> f(n+1,0);
    f[0]=n;
    rep(x,1,n+1) f[x] = (sumkd[x+1]-sumkd[0] + x*(sumd[n+1]-sumd[x+1]))/x;//min(k,x)なので、x以下の場合だけkかける
    
    int ans=n;
    rep(k,1,n+1){
        while(f[ans]<k) ans--;
        cout<<ans<<en;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}
