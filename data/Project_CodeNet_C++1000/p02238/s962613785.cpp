#include<bits/stdc++.h>
#define REP(i,n) for(long long i=0;i<n;++i)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
using namespace std;
int n,graph[101][101],visit[101];
int d[101],f[101],t;
const int WHITE=0;
const int GRAY=1;
void dfs(int u){
    visit[u]=GRAY;
    d[u]=++t;
    FOR(v,1,n+1){
        if(graph[u][v]==0) continue;
        if(visit[v]==WHITE) dfs(v);
    }
    f[u]=++t;
    //printf("%d %d %d\n",u,d[u],f[u]);
}
int main(){
    int u,k,v;
    scanf("%d",&n);
    REP(i,n){
        scanf("%d%d",&u,&k);
        REP(j,k){
            scanf("%d",&v);
            graph[u][v]=1;
        }
    }
    FOR(i,1,n+1){
        if(visit[i]==WHITE) dfs(i);
    }
    FOR(i,1,n+1){
        printf("%d",i);
        printf(" %d %d\n",d[i],f[i]);
    }
    return 0;
}


