#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

vector<int> v[101];
vector<int> dist;
queue<int> q;

int bfs() {
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int i = 0; i < v[c].size(); i++) {
            if (dist[v[c][i]] == -1) {
                dist[v[c][i]] = dist[c] + 1;
                q.push(v[c][i]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    dist.resize(n + 1, -1);

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            v[u].push_back(a);
        }
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}