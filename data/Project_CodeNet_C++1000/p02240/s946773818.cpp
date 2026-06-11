#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M, Q;
vector< vector<int> > graph;
vector< int > group;

void dfs(int u, int num) {
    group[u] = num;
    for (int v : graph[u])
        if (group[v] == -1) dfs(v, num);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    graph.resize(N+1); group.resize(N+1);
    for (int j = 0; j < M; ++j) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    fill(begin(group), end(group), -1);
    int group_num = 0;
    for (int j = 1; j <= N; ++j) {
        if (group[j] == -1) dfs(j, group_num++);
    }

    cin >> Q;
    for (int j = 0; j < Q; ++j) {
        int u, v; cin >> u >> v;
        cout << (group[u] == group[v] ? "yes" : "no") << endl;
    }

    return 0;
}