#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;
using namespace std;

struct SCC{
    vector<vector<int> > g,rg;
    vector<int> vs,cmp,used;
    SCC(int v):g(v),rg(v),cmp(v,-1),used(v,0){}
    
    void add_edge(int src,int dst){
        g[src].pb(dst);
        rg[dst].pb(src);
    }
    void dfs(int v){
        used[v]=true;
        rep(i,g[v].size()){
            if(!used[g[v][i]]) dfs(g[v][i]);
        }
        vs.pb(v);
    }
    void rdfs(int v,int k){
        used[v]=true;
        cmp[v]=k;
        rep(i,rg[v].size()){
            if(!used[rg[v][i]]) rdfs(rg[v][i],k);
        }
    }
    int scc(){
        fill(used.begin(),used.end(),0);
        vs.clear();
        rep(i,used.size()){
            if(!used[i]) dfs(i);
        }
        fill(used.begin(),used.end(),0);
        int k=0;
        for(int i=vs.size()-1;i>=0;--i){
            if(!used[vs[i]]) rdfs(vs[i],k++);
        }
        return k;
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    SCC scc(v);
    int s,t;
    rep(i,e){
        cin>>s>>t;
        scc.add_edge(s,t);
    }
    int k=scc.scc();
    vector<int> ans(v);
    if(v==k){
        rep(i,v) ans[scc.cmp[i]]=i;
        rep(i,v) cout<<ans[i]<<endl;
    }
    return 0;
}