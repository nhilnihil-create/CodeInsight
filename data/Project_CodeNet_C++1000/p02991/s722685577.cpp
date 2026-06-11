#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;
const ll MOD=1e9+7;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;++i) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]>rank[ry]) par[ry]=rx;
        else par[rx]=ry;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    int cnt(int n){
        int res=0;
        for(int i=0;i<n;++i){
            if(root(i)==i) res++;
        }
        return res;
    }
};

int main(){
    int N,M;cin>>N>>M;
    vector<vector<int> > G(N);
    for(int i=0;i<M;++i){
        int u,v;cin>>u>>v;u--;v--;
        G[u].push_back(v);
    }
    int s,t;cin>>s>>t;s--;t--;
    vector<vector<ll> > d(N,vector<ll>(3,-1));
    queue<ii> que;
    d[s][0]=0;
    que.push(ii(s,0));
    while(!que.empty()){
        ii p=que.front();que.pop();
        int u=p.first,parity=p.second;
        int np=(parity+1)%3;
        for(auto v:G[u]){
            if(d[v][np]>=0) continue;
            d[v][np]=d[u][parity]+1;
            que.push(ii(v,np));
        }
    }
    if(d[t][0]==-1) cout<<-1<<endl;
    else cout<<d[t][0]/3<<endl;
    return 0;
}