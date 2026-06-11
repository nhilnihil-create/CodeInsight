#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;
using edge_set = unordered_set<int>;

int main() {

    int V, E;
    cin >> V >> E;

    int count = 0;
    pair<int, int> order[V];
    edge_set indeg[V], outdeg[V];

    for (int i = 0; i < V; i++) {
        order[i].second = i;
    }

    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        indeg[t].insert(s);
        outdeg[s].insert(t);
    }

    queue<int> que;

    for (int i = 0; i < V; i++) {
        if (indeg[i].empty()) {
            que.push(i);
        }
    }

    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : outdeg[u]) {
            indeg[v].erase(u);
            if (indeg[v].empty()) {
                que.push(v);
            }
        }
        order[u].first = ++count;
    }

    //count < |V| なら閉路がある

    sort(order, order + V);

    for (int i = 0; i < V; i++) {
        cout << order[i].second << endl;
    }
}
