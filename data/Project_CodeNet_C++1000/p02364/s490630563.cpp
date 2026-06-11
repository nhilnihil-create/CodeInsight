#include "bits/stdc++.h"

using namespace std;

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A

vector<int> parents;
vector<int> ranks;

int init(int n) {
    parents = vector<int>(n, 0);
    ranks = vector<int>(n, 0);
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }
}

int find(int x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }

    if (ranks[x] > ranks[y]) {
        parents[y] = x;
    }
    else if (ranks[y] > ranks[x]) {
        parents[x] = y;
    }
    else {
        parents[y] = x;
        ++ranks[x];
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

struct Edge {
    int start;
    int end;
    int weight;
};

bool comp(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

void Main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), comp);
    init(V);
    int ans = 0;
    for (int i = 0; i < E; ++i) {
        if (!same(edges[i].start, edges[i].end)) {
            unite(edges[i].start, edges[i].end);
            ans += edges[i].weight;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

