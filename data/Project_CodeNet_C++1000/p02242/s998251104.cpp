#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;
typedef long long ll;
const int INF = 1e+7;
typedef pair<int,int> P;

struct dijkstra{
    vector<int> color;
    vector<vector<P>> adj;
    vector<int> d;
    vector<int> p;
    int n_;
    dijkstra(int n):color(n,0),adj(n),d(n,INF),p(n,-1){
        n_ = n;
    }
    void init(){
        rep(i,n_){
            int u,k;cin>>u>>k;
            rep(j,k){
                int v,c;cin>>v>>c;
                P tmp = make_pair(v,c);
                adj[i].push_back(tmp);
            }
        }
    }
    void solve(){
        init();
        d[0] = 0;
        p[0] = -1;
        while(true){
            int mincost = INF;
            int u;
            rep(i,n_){
                if(color[i]!=2 && d[i]<mincost){
                    mincost = d[i];
                    u = i;
                }
            }
            if(mincost == INF)break;
            color[u] = 2;
            for(P v:adj[u]){    
                if(color[v.first]!=2 && d[u]+v.second < d[v.first]){
                    d[v.first] = d[u] + v.second;
                    p[v.first] = u;
                    color[v.first] = 1;
                }
            }
        }
        rep(i,n_){
            cout<<i<<" "<<d[i]<<endl;
        }
    }
};


int main(){
    int n;cin>>n;
    dijkstra dj(n);
    dj.solve();
    return 0;
}
