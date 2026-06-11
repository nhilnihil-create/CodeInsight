#include <bits/stdc++.h>
#include <vector>
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;
double p;

int c[MX];
int vis[MX];
vector<vector<int>> g;
void dfs(int v) {
    vis[v]=1;
    for(auto cv: g[v]) {
        if(vis[cv]>0) continue;
        c[cv]+=c[v];
        dfs(cv);
    }
}

signed main() {
    int n,q;
    cin >> n >> q;
    g.resize(n);
    rep(i,n-1) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,q) {
        int p,x;
        cin >> p >> x;
        p--;
        c[p]+=x;
    }
    dfs(0);
    rep(i,n)cout << c[i] <<" "<< flush;
    cout << "" << endl;
    return 0;
}

