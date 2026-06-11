#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n,m,u,v,s,t;
    cin >> n >> m;
    vector<int> E[n];
    rep(i,m) {
        cin >> u >> v;
        E[u-1].push_back(v-1);
    }
    cin >> s >> t;
    s--;
    t--;
    int dist[n][3];
    rep(i,n) rep(j,3) dist[i][j] = -1;

    queue<pair<int, int>> que;
    que.push({s,0});
    dist[s][0] = 0;
    while (!que.empty()) {
        pair<int, int> q = que.front();
        int f = q.first;
        int d = q.second;
        que.pop();
        for(int to : E[f]) {
            if(dist[to][(d+1)%3] == -1) {
                dist[to][(d+1)%3] = dist[f][d] + 1;
                que.push({to,(d+1)%3});
            }
        }
    }
    if (dist[t][0] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[t][0] / 3 << endl;
    }
    return 0;
}
