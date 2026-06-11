#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using pll = pair<ll,ll>;
using vll = vector<pll>;
using vl  = vector<ll>;
using vvl = vector<vl>;
const ll INFL = (1LL<<60);
vvl edges;
vl dists;

int main() {
    int ans=-1;
    int N,M;
    cin>>N>>M;
    edges.resize(3*N);
    dists.assign(3*N,INFL);
    for (int i=0;i<M;++i) {
        int u,v;cin>>u>>v;u--;v--;
        edges[u].push_back(v+N);
        edges[u+N].push_back(v+2*N);
        edges[u+2*N].push_back(v);
    }
    int S,T;
    cin>>S>>T;S--;T--;
    priority_queue<pll> que;
    que.push(pll(0,S));
    while(!que.empty()){
        ll d=-que.top().first,node=que.top().second;que.pop();
        if (dists[node]!=INFL)continue;
        dists[node]=d;
        if(node==T){ans=dists[T]/3;break;}
        for(auto e:edges[node]){
            que.push(pll(-d-1,e));
        }
    }
    cout<<ans<<endl;
    return 0;
}
