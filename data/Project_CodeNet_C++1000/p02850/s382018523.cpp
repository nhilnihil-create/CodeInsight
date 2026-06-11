#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

vector<vector<pii>>graph;
int n;

// v: 頂点、p: 親、pc: 親から来た辺の色、res: 色
void dfs(int v, int p, int pc, vector<int> &res){
    int color = 1;
    if(color==pc)color++;
    for(auto i:graph[v]){
        // (隣接頂点, 辺番号)
        if(i.first==p)continue;
        res[i.second] = color;
        dfs(i.first, v, color, res);
        color++;
        if(color == pc)color++;
    }
}
int main(){
    cin >> n;
    graph.assign(n, vector<pii>());
    vector<int>ans(n-1, 1);
    rep(i, 0, n-1){
        int p, q;
        cin >> p >> q;
        p--,q--;
        graph[p].push_back({q, i});
        graph[q].push_back({p, i});
    }
    int ans2=-1;
    rep(i, 0, n)ans2=max(ans2,(int)graph[i].size());
    dfs(0, -1, -1, ans);
    cout << ans2 << endl;
    for(auto i:ans){
        cout << i << endl;
    }
}