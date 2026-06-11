#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define whole(xs) (xs).begin(),(xs).end()

vector< vector<int> > G1, G2;
int V;
vector<bool> used;
void init() {
    G1.clear(); G1.resize(V);
    G2.clear(); G2.resize(V);
    used.clear(); used.resize(V);
}
void addEdge(int from, int to) {
    G1[from].push_back(to);
    G2[to].push_back(from);
}
vector<int> vs;
void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < G1[v].size(); i++) {
        if (!used[ G1[v][i] ]) dfs1(G1[v][i]);
    }
    vs.push_back(v);
}
void dfs2(int v, int k, vector<int>& order) {
    used[v] = true;
    order[v] = k;
    for (int i = 0; i < G2[v].size(); i++) {
        if (!used[ G2[v][i] ]) dfs2(G2[v][i], k, order);
    }
}
int solve(vector<int>& ord) {
    fill(whole(used), false);
    vs.clear();
    for (int v = 0; v < V; v++) {
        if (!used[v]) dfs1(v);
    }
    fill(whole(used), false);
    int k = 0;
    ord.clear(); ord.resize(V, -1);
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) dfs2(vs[i], k++, ord);
    }
    return k;
}

int main() {
    int E;
    scanf("%d %d\n", &V, &E);
    init();
    for (int i = 0; i < E; i++) {
        int s, t; scanf("%d %d\n", &s, &t);
        addEdge(s, t);
    }
    vector<int> ord;
    solve(ord);
    vector< pair<int, int> > p;
    for (int i = 0; i < V; i++) {
        p.push_back(make_pair(ord[i], i));
    }
    sort(whole(p));
    for (int i = 0; i < V; i++) {
        printf("%d\n", p[i].second);
    }
    return 0;
}