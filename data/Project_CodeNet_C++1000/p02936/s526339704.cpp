#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};

int n;
vector<vector<int>> G;
vector<int> ans;

void dfs(int u, int p=-1) {
    for (int v : G[u]) {
        if (v==p) continue;
        ans[v] += ans[u];
        dfs(v,u);
    }
}

int main() {
    int q;
    cin>>n>>q;
    G.resize(n); ans.resize(n);
    rep(i,n-1) {
        int a,b; cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,q) {
        int p,x; cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0);
    rep(i,n) cout << ans[i] << endl;
}