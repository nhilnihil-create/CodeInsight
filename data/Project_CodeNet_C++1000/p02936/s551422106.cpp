#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using Graph=vector<vector<int>>;

vector<int> cnt;
void dfs(Graph& G, int v, int p){
    for(auto nv:G[v]){
        if(nv==p) continue;
        cnt[nv]+=cnt[v];
        dfs(G,nv,v);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    Graph G(n);
    cnt.assign(n,0);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a; --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<q;++i){
        int p,x;
        cin>>p>>x;
        --p;
        cnt[p]+=x;
    }
    dfs(G,0,-1);
    for(int i=0;i<n;++i) cout<<cnt[i]<<" ";
}