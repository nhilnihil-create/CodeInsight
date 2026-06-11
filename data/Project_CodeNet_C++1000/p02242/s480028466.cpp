#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

vector<pint> vp[500001];
int d[100001];
int INF=1000100010;
int n;
int dijkstra(int st){
    priority_queue<pint,vector<pint>,greater<pint> > pq;
    rep(i,n) d[i]=INF;
    d[st]=0;
    pq.push(make_pair(0,st));
    while(!pq.empty()){
        pint pi=pq.top();pq.pop();
        int t=pi.second;
        if(d[t]<pi.first) continue;
        for(auto it:vp[t]){
            if(d[it.second]>d[t]+it.first){
                d[it.second]=d[t]+it.first;
                pq.push(make_pair(d[it.second],it.second));
            }
        }
    }
}
int main(){
    cin>>n;
    int u,k,v,c;
    rep(i,n){
        cin>>u>>k;
        rep(j,k){
            cin>>v>>c;
            vp[u].pb(c,v);
        }
    }
    dijkstra(0);
    rep(i,n){
        cout<<i<<" "<<d[i]<<endl;
    }
    return 0;
}
