#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

#define mx 200005
vector<int> g[mx];
int vis[mx];

void dfs(int nd, int comp){
    if(vis[nd]>0) return;
    vis[nd]=comp;
    for(auto e : g[nd]) dfs(e,comp);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    memset(vis,0,sizeof(vis));

    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cc=1;
    for(int i=0;i<n;i++) if(!vis[i]){
        dfs(i,cc);
        cc++;
    }

    map<int,int> freq;
    for(int i=0;i<n;i++) freq[vis[i]]++;

    int mf=0;
    for(auto e : freq) if(e.second > mf){
        mf=e.second;
    }
    printf("%d\n",mf);
}
