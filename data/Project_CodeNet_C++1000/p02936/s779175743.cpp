#include<iostream>
#include<vector>
using namespace std;

int n,q;
vector<vector<int>> g(200005,vector<int>());
vector<int> ans(200005);

void dfs(int v,int p){
    for(int nv : g[v]){
        if(nv==p) continue;
        ans[nv]+=ans[v];
        dfs(nv,v);
    }
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        int p,x;
        cin>>p>>x;
        p--;
        ans[p]+=x;
    }
    dfs(0,-1);
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
}