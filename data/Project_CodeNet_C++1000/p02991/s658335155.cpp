#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=1e5+10,M=1e9+7;
int n,m,a,b;
int s,t;
int vis[mxN][4];
vector<int>adj[mxN];

int bfs(){
    queue<pii>fila;
    fila.push({s,0});    
    while(!fila.empty()){
        int u=fila.front().first;
        int d=fila.front().second;
        fila.pop();
        if(vis[u][d%3])continue;
        vis[u][d%3]=true;
        if(u==t && d%3==0)return d/3;
        for(int v:adj[u]){
            fila.push({v,d+1});
        }
    }
    return -1;
}



// LONG LONG CASE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].pb(b);
    }
    cin>>s>>t;    
    cout<< bfs();


}