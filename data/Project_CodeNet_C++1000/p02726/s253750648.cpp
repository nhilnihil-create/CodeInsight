#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
 int N, x, y;
cin >> N >> x >> y;
--x; --y;
    Graph G(N);
    G[0].push_back(1);
    G[N-1].push_back(N-2);
    for (int i = 1; i < N-1 ; ++i) {
        G[i].push_back(i+1);
        G[i].push_back(i-1);
    }
    G[x].push_back(y);
    G[y].push_back(x);
  
int ans[N] = {0};
for(int p = 0; p < N; p++){
     vector<int> dist(N, -1); 
    queue<int> que;
    dist[p] = 0;
    que.push(p); 

    while (!que.empty()) {
        int v = que.front(); 
        que.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue; 
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
     for(int u= 0; u<N;u++) ans[dist[u]]++;
}
for (int i = 1; i<=N-1; i++)cout << ans[i] / 2 << endl;
return 0;
}