#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &G, vector<int> &dist, vector<int> &prev, int start) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int next_v : G[v]) {
            if (dist[next_v] != -1) continue;
            dist[next_v] = dist[v] + 1;
            prev[next_v] = v;
            q.push(next_v);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    
    vector<int> dist(N, -1), prev(N, -1);
    bfs(G, dist, prev, 0);

    cout << "Yes" << endl;
    for (int i = 1; i < N; i++) cout << prev[i] + 1 << endl;
}