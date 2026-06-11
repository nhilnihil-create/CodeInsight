#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int MAX_V = 10000;

vector<int> G[MAX_V];
list<int> sorted;
bool V[MAX_V];
int v, e;
int indeg[MAX_V];

void bfs(int s) {
    queue<int> que; que.push(s);
    V[s] = true;

    while (!que.empty()) {
        int u = que.front(); que.pop();
        sorted.push_back(u);
        for (auto i = 0; i < G[u].size(); i++) {
            int ver = G[u][i]; indeg[ver]--;
            if (indeg[ver] == 0 && !V[ver]) {
                V[ver] = true;
                que.push(ver);
            }
        }
    }
}

void topologicalSort() {
    for (int i = 0; i < v; i++) {
        indeg[i] = 0;
    }

    for (int u = 0; u < v; u++) {
        for (auto i = 0; i < G[u].size(); i++) {
            int ver = G[u][i];
            indeg[ver]++;
        }
    }

    for (int u = 0; u < v; u++) {
        if (indeg[u] == 0 && !V[u]) bfs(u);
    }
}




int main(void) {
    cin >> v >> e;
    for (int i = 0; i < v; i++) {
        V[i] = false;
    }

    int s, t;
    for (int i = 0; i < e; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    topologicalSort();

    for (auto it = sorted.begin(); it != sorted.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}