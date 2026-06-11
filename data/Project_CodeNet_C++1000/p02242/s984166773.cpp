#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

int n;
const int MAX = 110;
const int INF = 1e9;
int D[MAX];
struct edge{
    int cost, to;
};
vector<edge> G[MAX];

void dijkstra(int s){
    for(int i = 0; i < n; i++){
        D[i] = INF;
    }
    D[s] = 0;
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, s});
    while(!q.empty()){
        P p = q.top();
        q.pop();
        int now = p.second;
        for(int i = 0; i < G[now].size(); i++){
            edge e = G[now][i];
            if(D[e.to] > D[now] + e.cost){
                D[e.to] = D[now] + e.cost;
                q.push({D[e.to], e.to});
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        int u, k;
        cin >> u >> k;
        for(int i = 0; i < k; i++){
            int v, c;
            cin >> v >> c;
            G[u].push_back({c, v});
        }
    }

    dijkstra(0);

    for(int i = 0; i < n; i++){
        cout << i << ' ' << D[i] << endl;
    }

    return 0;
}
