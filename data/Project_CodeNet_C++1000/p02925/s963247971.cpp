#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct edge {
    int to;
};

int N;
int dfs(int n, vector<vector<edge>>& E, vector<int>& dist, vector<bool>& visited, bool& hasCycle) {
    if (dist[n] != -1)
        return dist[n];

    visited[n] = true;
    int ret = 0;
    for (edge e : E[n]) {
        if (dist[e.to] == -1 && visited[e.to]) {
            hasCycle = true;
            continue;
        }
        ret = max(ret, dfs(e.to, E, dist, visited, hasCycle) + 1);
    }

    return dist[n] = ret;
}

int main() {
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N - 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<vector<edge>> E(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j + 1 < N - 1; j++) {
            int now = min(i, A[i][j]) * N + max(i, A[i][j]);
            edge e;
            e.to = min(i, A[i][j + 1]) * N + max(i, A[i][j + 1]);
            E[now].push_back(e);
        }
    }

    vector<int> dist(N * N, -1);
    vector<bool> visited(N * N, false);
    bool hasCycle = false;
    for (int i = 0; i < N; i++) {
        int root = min(i, A[i][0]) * N + max(i, A[i][0]);
        dfs(root, E, dist, visited, hasCycle);
    }

    if (hasCycle) {
        cout << -1 << endl;
    } else {
        cout << *max_element(dist.begin(), dist.end()) + 1 << endl;
    }
}
