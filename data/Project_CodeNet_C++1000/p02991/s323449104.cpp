#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<ll,l_l> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll n,m,s,t;
vl path[100100];
ll dp[100010][4];

void Dijkstra(){
    rep(i,n){
        rep(j,4){
            dp[i][j]=LINF;
        }
    }
    dp[s][0]=0;
    priority_queue<lll,vector<lll>,greater<lll>> pq;
    pq.push({0,{s,0}});
    while(pq.size()){
        auto it=pq.top();pq.pop();
        ll nowpos=it.se.fi;
        ll nowcost=it.fi;
        ll nowt=it.se.se;
        for(auto nxtpos:path[nowpos]){
            ll nxtcost=nowcost+((nowt+1)%3==0?1:0);
            if(chmin(dp[nxtpos][(nowt+1)%3],nxtcost)){
                pq.push({nxtcost,{nxtpos,(nowt+1)%3}});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    rep(i,m){
        ll u,v;cin>>u>>v;
        u--;v--;
        path[u].pb(v);
    }
    cin>>s>>t;
    s--;t--;
    Dijkstra();
    if(dp[t][0]==LINF)cout<<-1<<endl;
    else cout<<dp[t][0]<<endl;
    return 0;
}