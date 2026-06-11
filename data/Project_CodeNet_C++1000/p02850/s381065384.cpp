#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
const int MOD=1e9+7;
const int INF=1e15;

using Edge=pair<int,int>;
using Graph=vector<vector<Edge>>;
int N;
Graph G;

void dfs(int v,int p,int pc,vector<int> &res){
    int color=1;
    if(color==pc)++color;
    for(auto e:G[v]){
        if(e.first==p)continue;
        res[e.second]=color;
        dfs(e.first,v,color,res);
        color++;
        if(color==pc)color++;
    }
}

signed main(){
    cin>>N;
    G.assign(N,vector<Edge>());
    REP(i,N-1){
        int a,b;cin>>a>>b;a--;b--;
        G[a].eb(b,i);
        G[b].eb(a,i);
    }
    int max_color=0;
    REP(i,N)max_color=max(max_color,(int)G[i].size());
    vector<int>res(N-1,-1);
  	dfs(0,-1,-1,res);
    cout<<max_color<<endl;
    for(auto v:res)cout<<v<<endl;
}