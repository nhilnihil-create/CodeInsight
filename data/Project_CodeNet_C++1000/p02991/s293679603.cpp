#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int main() {
    int N, M, S, T;
    cin>>N>>M;
    vvi G(N);
    REP(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
    }
    cin >> S >> T;
    S--; T--;

    vvi dist(N, vi(3, -1));
    dist[S][0] = 0;
    queue<pint> que;
    que.push({S, 0});
    while(!que.empty()){
        auto cur = que.front(); que.pop();
        int v = cur.first;
        int parity = cur.second;
        for(int x: G[v]){
            int np = (parity+1) % 3;
            if(dist[x][np] == -1){
                dist[x][np] = dist[v][parity] + 1;
                que.push({x, np});
            }
        }
    }
    int ans = 0;
    if(dist[T][0] == -1) ans = -1;
    else ans = dist[T][0]/3;
    cout << ans << endl;
}