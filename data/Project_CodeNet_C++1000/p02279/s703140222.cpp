#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int par;
    int depth;
    vector<int> list;
};

Node G[100001];

void dfs(int n, int m)
{
    G[n].depth = m;
    for(int i = 0; i < G[n].list.size(); ++i){
        dfs(G[n].list[i], m + 1);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n,id,k,c;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i){
        G[i].par = -1;
    }
    
    for(int i = 0; i < n; ++i){
        scanf("%d%d",&id,&k);
        for(int i = 0; i < k; ++i){
            scanf("%d",&c);
            G[c].par = id;
            G[id].list.push_back(c);
        }
    }
    
    int root;
    
    for(int i = 0; i < n; ++i){
        if(G[i].par == -1){
            root = i;
            break;
        }    
    }
    
    dfs(root,0);
    
    for(int i = 0; i < n; ++i){
         printf("node %d: parent = %d, depth = %d, %s, [", i, G[i].par, G[i].depth, i == root ? "root" : G[i].list.size() == 0 ? "leaf" : "internal node");
         for(int j = 0; j < G[i].list.size(); ++j){
             if(j != 0) printf(", ");
             printf("%d",G[i].list[j]);
         }
         printf("]\n");
    }
    
}