#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);

struct Edge {
    int to, id;
};

int color[MX];
int x[MX];
int y[MX];

vector<vector<Edge>> g;
vector<int> ans;
int ma;
void dfs(int vertex,int c = -1, int p=-1) {
    int tmp = 1;
    //cout << vertex << endl;
    for(auto v: g[vertex]) {
        int u = v.to, ei = v.id;
        if(u==p) continue;
        if(tmp==c) tmp++;
        ans[ei] = tmp;
        ma = max(ma, ans[ei]);
        tmp++;
        dfs(u, ans[ei], vertex);
    }
}

signed main(){
    ll n;
    cin >> n;
    color[0] = 1;
    g.resize(n);
    ans.resize(n-1);
    rep(i,n-1) {
        ll a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(Edge{b,i});
        g[b].push_back(Edge{a,i});

    }

    dfs(0);
    cout << ma << endl;
    for(auto a: ans) cout << a << endl;
    return 0;
}

