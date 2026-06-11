#include<bits/stdc++.h>
#define REP(i,n) for(long long i=0;i<n;++i)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
using namespace std;
const int INF=INT_MAX;

vector< int > G[100000];
list< int > out;
bool V[100000];
int N;
int indeg[100000];

void bfs(int s){
    queue< int > q;
    q.push(s);
    V[s]=true;
    while(!q.empty()){
        int u=q.front();q.pop();
        out.push_back(u);
        REP(i,G[u].size()){
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0&&!V[v]){
                V[v]=true;
                q.push(v);
            }
        }
    }
}

void tsort(){
    REP(i,N){
        indeg[i]=0;
    }

    REP(u,N){
        REP(i,G[u].size()){
            int v=G[u][i];
            indeg[v]++;
        }
    }

    REP(u,N) if(indeg[u]==0&&!V[u]) bfs(u);

    for(auto it=out.begin();it!=out.end();++it) printf("%d\n",*it);
}

int main(){
    int s,t,M;

    scanf("%d%d",&N,&M);

    REP(i,N) V[i]=false;

    REP(i,M){
        scanf("%d%d",&s,&t);
        G[s].push_back(t);
    }

    tsort();

    return 0;
}


