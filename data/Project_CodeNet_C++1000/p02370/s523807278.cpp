#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
 
static const int MAX=100000;
static const int INFTY=(1<<29);
 
vector<int> G[MAX];
list <int> out;
bool V[MAX];
int N;
int indeg[MAX];
 
void bfs(int s){
    queue<int> q;
    q.push(s);
    V[s]=true;
    while(q.size()){
        int u=q.front();
        q.pop();
        out.push_back(u);
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indeg[v]--;
            if(indeg[v]==0 && !V[v]){
                V[v]=true;
                q.push(v);
            }
        }
    }
}
 
void tsort(){
    memset(indeg,0,sizeof(indeg));
    for(int u=0;u<N;u++){
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            indeg[v]++;
        }
    }
    for(int u=0;u<N;u++){
        if(indeg[u]==0 && !V[u])bfs(u);
    }
    for(list<int>::iterator it=out.begin();it!=out.end();it++){
        cout << *it << endl;
    }
}
 
int main(void){
    int s,t,M;
    scanf("%d %d",&N,&M);
    memset(V,false,sizeof(V));
    for(int i=0;i<M;i++){
        scanf("%d %d",&s,&t);
        G[s].push_back(t);
    }
    tsort();
    return 0;
     
}
