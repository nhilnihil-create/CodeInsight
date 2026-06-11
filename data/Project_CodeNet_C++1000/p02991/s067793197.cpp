#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

vi g[100010];
int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    ll n, m; cin >> n >> m;
    rep(i,m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    int s,t; cin >> s >> t;
    vvi d(n+1, vi(3, INF));
    queue<pii> Q;
    Q.emplace(s, 0);
    d[s][0] = 0;
    while(!Q.empty()){
        pii p = Q.front(); Q.pop();
        int v = p.fi, c = p.se;
        int nc = (c + 1) % 3;
        for(auto u : g[v]){
            if(d[u][nc] == INF){
                d[u][nc] = d[v][c] + 1;
                Q.emplace(u, nc);
            }
        }
    }

    if(d[t][0] == INF) cout << -1 << endl;
    else cout << d[t][0]/3 << endl;
    return 0;
}