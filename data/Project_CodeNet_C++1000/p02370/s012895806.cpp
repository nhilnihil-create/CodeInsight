#include <iostream>
#include <vector>

using namespace std;

vector<int> G[10010];
vector<int> L;
int visited[10010];

void dfs(int v)
{
    if (visited[v]) return;
    visited[v]=true;
    for(auto& u: G[v]) dfs(u);
    L.push_back(v);
}

int main()
{
    int V, E; cin>>V>>E;
    for(int i=0; i<E; ++i) {
        int s, t; cin>>s>>t;
        G[s].push_back(t);
    }

    for(int i=0; i<V; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }

    for(int i=V-1; i>=0; --i) cout<<L[i]<<endl;
}

