#include <iostream>
#include <vector>
using namespace std;

const int N=200001;
bool vis[N];
int count=0;

void dfs(vector<vector<int>> &g, int root){
    vis[root]=true;
    count+=1;
    for(int v:g[root]){
        if(!vis[v]){
            dfs(g,v);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i<m;++i){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx=0;
    for(int i=0;i<n; ++i){
        count=0;
        if(!vis[i]){
            dfs(g,i);
        }
        mx=max(mx,count);
    }
    cout<<mx<<endl;
    return 0;
}