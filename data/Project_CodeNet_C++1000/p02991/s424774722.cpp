#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef int64_t Int;
typedef pair<int,int> pii;
const int INF = 999999999;

vector<vector<int>> G(300010);
vector<int> dist(300010, INF);

void dijkstra(int s){
    // first:最短距離 second:頂点番号
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[s] = 0;
    q.push(pii(0, s));

    while (!q.empty()){
        int cur_d = q.top().first;
        int cur_v = q.top().second;
        q.pop();

        if (cur_d > dist[cur_v]) continue;

        for (int i = 0; i < G[cur_v].size(); i++){
            int to = G[cur_v][i];
            if (dist[cur_v] + 1 < dist[to]){
                dist[to] = dist[cur_v] + 1;
                q.push(pii(dist[to], to));
            }
        }
    }
}


int main(){
    int N, M, S, T;
    cin >> N >> M;
    rep(i, M){
        int u, v; cin >> u >> v; u--; v--;
        G[3*u].push_back(3*v+1);
        G[3*u+1].push_back(3*v+2);
        G[3*u+2].push_back(3*v);
    }
    cin >> S >> T; S--; T--;

    dijkstra(3*S);

    if (dist[3*T] == INF){
        cout << -1 << endl;
    } else {
        cout << dist[3*T]/3 << endl;
    }    
}