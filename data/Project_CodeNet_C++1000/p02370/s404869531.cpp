#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#define MAXV 10005
#define MAXE 100005
using namespace std;

int N,E;
bool V[MAXV];
vector<int> G[MAXV],out;
int indeg[MAXV];

void bfs(int u){
    queue<int> q;
    q.push(u);
    V[u]=true;
    int i;
    while(!q.empty()){
        int a=q.front();q.pop();
        out.push_back(a);
        for(i=0;i<G[a].size();i++){
            int v=G[a][i];
            indeg[v]--;
            if(indeg[v]==0&&!V[v]){
                V[v]=true;
                q.push(v);
            }
        }
    }
}

void tsort(){
     int i;
     for(i=0;i<N;i++){
        if(!V[i]&&indeg[i]==0){
            bfs(i);
        }
     }
     for(i=0;i<out.size();i++)cout<<out[i]<<endl;
}

int main(){
    cin>>N>>E;
    int i,j;
    for(i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }

    memset(indeg,0,sizeof(indeg));
    for(i=0;i<N;i++)V[i]=false;
    for(i=0;i<N;i++){
        for(j=0;j<G[i].size();j++){
            indeg[G[i][j]]++;
        }
    }
    tsort();
    return 0;
}