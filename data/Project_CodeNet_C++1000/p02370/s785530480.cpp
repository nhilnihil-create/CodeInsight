#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool used[10000];
vector<int> vs;
vector<int> ans;
vector<int> es[10000];
vector<int> res[10000];

void add_edge(int u, int v) {
    es[u].push_back(v);
    res[v].push_back(u);
}

void dfs1(int v) {
    used[v] = true;
    for (int i=0; i<es[v].size(); i++) {
        int u = es[v][i];
        if (!used[u]) dfs1(u);
    }
    vs.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    for (int i=0; i<res[v].size(); i++) {
        int u = res[v][i];
        if (!used[u]) dfs2(u);
    }
    ans.push_back(v);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add_edge(a, b);
    }

    fill(used, used+n, false);
    for (int i=0; i<n; i++) {
        if (!used[i]) dfs1(i);
    }

    fill(used, used+n, false);
    for (int i=vs.size()-1; i>=0; i--) {
        if (!used[vs[i]]) dfs2(vs[i]);
    }

    for (int i=0; i<ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
}