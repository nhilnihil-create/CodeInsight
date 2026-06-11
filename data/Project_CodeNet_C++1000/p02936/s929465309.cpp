#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    vector<vector<int>> adjlist(N, vector<int>());
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<int> counter(N, 0);
    for (int i=0; i<Q; i++) {
        int p, x;
        cin >> p >> x;
        counter[p-1] += x;
    }
    // dfs
    vector<bool> visited(N, false);
    queue<int> que;
    que.push(0);
    visited[0] = true;
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int child: adjlist[node]) {
            if (visited[child]) continue;
            counter[child] += counter[node];
            que.push(child);
            visited[child] = true;
        }
    }
    for (int i=0; i<N-1; i++) cout << counter[i] << " ";
    cout << counter[N-1] << endl;
}