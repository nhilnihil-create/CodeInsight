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
	ll to, cap, rev, col;
	Edge(ll _to, ll _cap, ll _rev, ll _col) {
	to = _to; cap = _cap; rev = _rev; col=_col;
	}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap, ll col) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size(), col));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1, col));
}

void solve(){
    ll n;
    cin>>n;
    ll n2=1<<n;
    Array s(n2);
    REP(i,n2) cin>>s[i];

    sort(all(s));
    vec<int> now;
    now.push_back(s.back());
    s.back()==-1;

    REP(i,n){
        vec<int> pre=now;
        sort(all(pre));
        int si=n2-1;
        while(pre.size()>0&&si>=0){
            if(s[si]==-1){
                --si;
                continue;
            }
            if(s[si]<pre.back()){
                now.push_back(s[si]);
                pre.pop_back();
                s[si]=-1;
            }
            --si;
        }
        if(pre.size()>0){
            cout<<"No"<<en;
            return;
        }
    }
    cout<<"Yes"<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}
