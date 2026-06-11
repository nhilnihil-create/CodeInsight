#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

struct TopologicalSort{
    vector<vector<int>> G;
    vector<int> used,indeg,order;
    TopologicalSort(int n):G(n),used(n,0),indeg(n,0){}
    void add_edge(int u,int v){
        G[u].push_back(v);
        ++indeg[v];
    }
    void bfs(int s){
        queue<int> que;
        que.emplace(s);
        used[s]=1;
        while(!que.empty()){
            int v=que.front(); que.pop();
            order.emplace_back(v);
            for (auto u:G[v]){
                --indeg[u];
                if (indeg[u]==0&&!used[u]){
                    used[u]=1;
                    que.emplace(u);
                }
            }
        }
    }
    vector<int> build(){
        rep(i,G.size()) if (indeg[i]==0&&!used[i]) bfs(i);
        return order;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;
    TopologicalSort T(V);
    rep(i,E){
        int s,t; cin >> s >> t;
        T.add_edge(s,t);
    }
    vector<int> ans=T.build();
    rep(i,V) cout << ans[i] << endl;
}
