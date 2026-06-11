#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct edge {
    edge(int n, int m){
        u = min(n, m);
        v = max(n, m);
    }
    int u, v;
};

vector<vector<int>> dist;
vector<vector<int>> nParent;
vector<vector<vector<edge>>> child;

void dfs(edge now){
    for(edge e : child[now.u][now.v]){
        if(nParent[e.u][e.v] == 0 || dist[e.u][e.v] == 1e9){
            dist[e.u][e.v] = 1e9;
            continue;
        }
        nParent[e.u][e.v]--;
        dist[e.u][e.v] = max(dist[e.u][e.v], dist[now.u][now.v] + 1);
        if(nParent[e.u][e.v] == 0){
            dfs(e);
        }
    }
}

int main(){
    int N;  cin >> N;
    vector<vector<int>> A(N, vector<int>(N-1, 0));
    for(int i=0; i<N; i++) for(int j=0; j<N-1; j++){
        cin >> A[i][j];  A[i][j]--;
    }

    child.resize(N, vector<vector<edge>>(N));
    nParent.resize(N, vector<int>(N, 0));
    dist.resize(N, vector<int>(N, 0));
    for(int i=0; i<N; i++) for(int j=0; j<N-2; j++){
        edge now = edge(i, A[i][j]);
        edge next = edge(i, A[i][j+1]);
        child[now.u][now.v].push_back(next);
        nParent[next.u][next.v]++;
    }

    vector<edge> root;
    for(int i=0; i<N; i++) for(int j=i+1; j<N; j++){
        edge e = edge(i, j);
        if(nParent[e.u][e.v] == 0){
            root.push_back(e);
        }
    }
    if(root.size() == 0){
        cout << -1 << endl;
        return 0;
    }

    for(edge r : root){
        dfs(r);
    }
    int ans = 0;
    for(int i=0; i<N; i++) for(int j=i+1; j<N; j++){
        ans = max(ans, dist[i][j]);
        if(dist[i][j] == 0 && nParent[i][j] != 0){
            ans = 1e9;
        }
    }
    if(ans >= 1e9){
        cout << -1 << endl;
    }else{
        cout << ans + 1 << endl;
    }
}
