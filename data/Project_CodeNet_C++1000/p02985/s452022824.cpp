#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(long long i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,N-1,0)
#define RREPS(i,n) RFOR(i,N,1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
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
const int INF=1e18;
const int MOD=1e9+7;
int N,K;
int dfs(int o,int k,const vector<vector<int>>&Graph){
    int nowc=(o==-1?K-1:K-2);
    if(K<Graph[k].size())return 0;
    else{
        int pat=1;
        for(auto v:Graph[k]){
            if(v==o)continue;
            pat*=nowc;
            nowc--;
            pat%=MOD;
        }
        for(auto v:Graph[k]){
            if(v==o)continue;
            pat*=dfs(k,v,Graph);
            pat%=MOD;
        }
        return pat%MOD;
    }
}

signed main(){
    cin>>N>>K;
    vector<vector<int>>Graph(N);
    REP(i,N-1){
        int a,b;cin>>a>>b;--a;--b;
        Graph[a].pb(b);
        Graph[b].pb(a);
    }
    cout<<K*dfs(-1,0,Graph)%MOD<<endl;
}