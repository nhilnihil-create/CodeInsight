#include<bits/stdc++.h>
using namespace std;

int n,m;

const int MAXN = 10010;
int par[MAXN],sz[MAXN];
vector<int> comps,orders,grf[MAXN],rev_grf[MAXN];
bool visited[MAXN];

int findcc(int x){
    return (x==par[x]) ? x : par[x]=findcc(par[x]);
}
bool unite(int a,int b){
    a = findcc(a);
    b = findcc(b);
    if(a==b){return false;}
    if( sz[a]<sz[b]){ swap(a,b);}
    par[b] = a;
    sz[a]+=sz[b];
    return true;
}

void dfs(int u){
    visited[u]=true;
    for(auto nbr: grf[u]){
        if(!visited[nbr]){
            dfs(nbr);
        }
    }
    orders.push_back(u);
}

void dfs2(int u){
    visited[u]=true;
    comps.push_back(u);
    for(auto nbr: rev_grf[u]){
        if(!visited[nbr]){
            dfs2(nbr);
        }
    }
}

void init()
{
    for(int i=0; i<n; i++){
        par[i]=i; sz[i]=1;
    }
    memset(visited,false,sizeof visited);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    memset(visited,false,sizeof visited);
    
    while(!orders.empty()){
        int x = orders.back(); orders.pop_back();
        if(!visited[x]){
            comps.clear();
            dfs2(x);
            for(auto c: comps){
                unite(x,c);
            }
        }
    }
}

void top_sort()
{
    memset(visited,false,sizeof visited);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(int i=n-1; i>=0; i--){
        cout<< orders[i] <<"\n";
    }   
}

int main() {
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        grf[x].push_back(y);
        rev_grf[y].push_back(x);
    }
    top_sort();
    
    
}
