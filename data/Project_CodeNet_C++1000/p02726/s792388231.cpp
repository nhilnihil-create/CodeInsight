#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    Graph G(N);
    rep(i, N - 1) {
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[X-1].push_back(Y-1);
    G[Y-1].push_back(X-1);

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++) {
        vector<int> dist(N, -1);
        queue<int> que;
        
        dist[i] = 0;
        que.push(i);
        
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            
            for (int nv : G[v]) {
                if (dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        for (int j = 0; j < N; j++) {
            ans[dist[j]]++;
        }
    }
    for (int i = 1; i < N; i++) {
        cout << ans[i]/2 << endl;
    }

    return 0;
}
