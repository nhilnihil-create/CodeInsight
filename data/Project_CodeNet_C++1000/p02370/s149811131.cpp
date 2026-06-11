#include <bits/stdc++.h>

using namespace std;

vector<int> adjList[10005], ts;
bool vis[10005];

void toposort(int u){
    vis[u] = true;
    for (int i=0; i<adjList[u].size(); i++){
        int v = adjList[u][i];

        if (!vis[v]) toposort(v);
    }
    ts.push_back(u);
}

int main(){

    ios_base::sync_with_stdio(0);

    // init
    memset(vis,0,sizeof(vis));

    int N, E;
    cin >> N >> E;

    int u, v;
    for (int i=0; i<E; i++){
        cin >> u >> v;

        adjList[u].push_back(v);
    }

    for (int i=0; i<N; i++){
        if (!vis[i]) toposort(i);
    }

    for (int i=ts.size()-1; i>=0; i--) cout << ts[i] << endl;

    return 0;
}