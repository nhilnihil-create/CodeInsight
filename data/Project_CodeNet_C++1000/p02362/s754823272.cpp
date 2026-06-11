#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

struct edge{
    int src,dst,cost;
    edge(int src,int dst,int cost):
    src(src),dst(dst),cost(cost){}
    };
vector<edge> ve;
int d[1001];
int inf=1000100010;
int v;
bool negcy=false;
int bellman_ford(int st){
    rep(i,v) d[i]=inf;
    d[st]=0;
    int cnt=0;
    while(1){
        bool update =false;
        rep(i,ve.size()){
            edge e=ve[i];
            if(d[e.src]!=inf&&d[e.dst]>d[e.src]+e.cost){
                d[e.dst]=d[e.src]+e.cost;
                update=true;
            }
        }
        if(!update) break;
        if(cnt>=ve.size()){
            negcy=true;break;
        }
        ++cnt;
    }
}
int main(){
    int e,r,s,t,ds;
    cin>>v>>e>>r;
    rep(i,e){
        cin>>s>>t>>ds;
        ve.pb(edge(s,t,ds));
    }
    bellman_ford(r);
    if(negcy) cout<<"NEGATIVE CYCLE"<<endl;
    else{
        rep(i,v){
        if(d[i]<inf) cout<<d[i]<<endl;
        else cout<<"INF"<<endl;
        }
    }
    return 0;
}