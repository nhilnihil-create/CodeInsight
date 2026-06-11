#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

/* topologicalSort */
#define topo_SIZE 10000

vector<int> topologicalSort(vector<vector<int> > G,int n=-1){
    int indeg[topo_SIZE] = {0},u;
    vector<int> ret,ret2;
    queue<int> que;
    
    if(n==-1) n=(int)G.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            indeg[G[i][j]]++;
        }
    }
    
    for(int i=0;i<n;i++){
        if(indeg[i]==0){
            que.push(i);
        }
    }
    
    while(!que.empty()){
        u = que.front();
        que.pop();
        
        ret.push_back(u);
        
        for(int i=0;i<G[u].size();i++){
            indeg[G[u][i]]--;
            if(indeg[G[u][i]]==0){
                que.push(G[u][i]);
            }
        }
    }
    
    if(n==(int)ret.size()){
        return ret;
    }else{
        return ret2;
    }
}

int main(){
    int v,e,a,b;
    vector<int> ans;
    vector<vector<int> > in(10000);
    
    scanf("%d%d",&v,&e);
    
    for(int i=0;i<e;i++){
        scanf("%d%d",&a,&b);
        
        in[a].push_back(b);
    }
    
    ans = topologicalSort(in,v);
    
    if(ans.size()==0){
        puts("-1");
        return 0;
    }
    
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
    
    return 0;
}