#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int n, m;
vector<vector<int>> G;
int s, t;
ll dist[100010][3];

ll bfs(){
    memset(dist, -1LL, sizeof(dist));
    dist[s][0] = 0;
    queue<P> stt;
    stt.push(P(s, 0));
    while(!stt.empty()){
        int v = stt.front().first;
        int m = stt.front().second;
        stt.pop();
        for(auto nv : G[v]){
            if(dist[nv][(m + 1) % 3] != -1){
                continue;
            }
            else{
                dist[nv][(m + 1) % 3] = dist[v][m] + 1;
                stt.push(P(nv, (m + 1) % 3));
            }
        }
    }
    if(dist[t][0] == -1) return -1;
    else return dist[t][0] / 3;
}

int main(void){
    cin >> n >> m;
    G.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        // 有向グラフなのでuからvだけ辺を張りましょう。
        // G[v].push_back(u);
    }
    cin >> s >> t;
    s--; t--;

    cout << bfs() << endl;

    return 0;
}