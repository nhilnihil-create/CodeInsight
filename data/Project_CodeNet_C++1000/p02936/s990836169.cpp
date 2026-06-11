#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int N, Q;
vector<vector<int>> graph(0);
struct node {
    int parent;
    int c;
};
vector<node> tree(0);
queue<int> q;

void make_tree() {
    int par;
    q.push(0);
    tree[0].parent = INT_MAX;
    while (!q.empty()) {
        par = q.front();
        q.pop();
        for (int i = 0; i < (int)graph[par].size(); i++) {
            if (tree[graph[par][i]].parent != -1) continue;
            tree[graph[par][i]].parent = par;
            tree[graph[par][i]].c += tree[par].c;
            q.push(graph[par][i]);
        }
    }
}

int main() {
    cin >> N >> Q;
    graph.resize(N);
    tree.assign(N, {-1, 0});
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int p, x;
    for (int i = 0; i < Q; i++) {
        cin >> p >> x;
        p--;
        tree[p].c += x;
    }
    make_tree();
    for (int i = 0; i < N; i++) {
        cout << tree[i].c;
        if (i != N - 1)
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}