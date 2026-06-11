#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

vector<ll> dijkstra(const vector<vector<pair<int,int>>> &graph,int s){
    int n=(int)graph.size();
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dist(n,linf);
    dist[s]=0;
    pq.push({0,s});
    while(pq.size()){
        auto p=pq.top();
        pq.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;
        for(auto edge:graph[v]){
            int u=edge.first;
            int w=edge.second;
            if(dist[v]+w<dist[u]){
                dist[u]=dist[v]+w;
                pq.push({dist[u],u});
            }
        }
    }
    return dist;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+n+n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        --a,--b;
        g[a].push_back({b+n,1});
        g[a+n].push_back({b+n+n,1});
        g[a+n+n].push_back({b,1});
    }
    int s,t;
    cin>>s>>t;
    --s,--t;
    vector<ll> d=dijkstra(g,s);
    cout<<(d[t]!=linf?d[t]/3:-1)<<endl;
}
