#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector< vector<int> > G(10001);
queue<int> que;
int n_v, n_e, u, v;
int in_degree[10001], ans[10001], idx;


int main(){

    memset(in_degree, 0, sizeof(in_degree));
    scanf("%d %d", &n_v, &n_e);
    for(int i=0; i<n_e; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        in_degree[v] += 1;
    }

    idx = 0;
    for(int i=0; i<n_v; i++) 
        if(in_degree[i]==0){
            ans[idx++] = i;
            que.push(i);     
        }

    while(!que.empty()){
        u = que.front();
        que.pop();
        for(int i=0; i<G[u].size(); i++){
            v = G[u][i];
            in_degree[v] -= 1;
            if(in_degree[v]==0){
                ans[idx++] = v;
                que.push(v);
            }
        }
    }
    for(int i=0; i<n_v; i++)
        printf("%d\n", ans[i]);
    return 0;
}
