#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;

vector<int>to[100010];

int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int u,v; cin>>u>>v;
        u--; v--;
        to[u].push_back(v);
    }
    int s,t;
    cin>>s>>t;
    s--; t--;
    vector<vector<int>>dist(n,vector<int>(3,INF));
    queue<P>q;
    q.push(P(s,0));
    dist[s][0]=0;
    while(!q.empty()){
        int v=q.front().first;
        int x1=q.front().second;
        int x2=(x1+1)%3;
        q.pop();
        for(int u:to[v]){
            if(dist[u][x2]!=INF)continue;
            dist[u][x2]=dist[v][x1]+1;
            q.push(P(u,x2));
        }
    }
    if(dist[t][0]==INF)cout<<-1<<endl;
    else cout<<dist[t][0]/3<<endl;
}