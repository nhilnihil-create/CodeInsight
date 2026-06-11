#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <array>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <list>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
    return s << "(" << p.first << ", " << p.second << ")";
}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    s << "[";
    for (int i = 0; i < v.size(); i++) s << (i == 0 ? "" : ", ") << v[i];
    s << "]";
    return s;
}

#define ALL(a) (a).begin(), (a).end()

using Weight = int;

// ??????????????????
struct Edge {
    int from, to;
    Weight weight;

    Edge() {}
    Edge(int to) : from(-1), to(to), weight(-1) {}
    Edge(int from, int to) : from(from), to(to), weight(-1) {}
    Edge(int from, int to, Weight weight) : from(from), to(to), weight(weight) {}

    bool operator<(const Edge& e) const {
        return (weight != e.weight) ? (weight < e.weight) : (from < e.from);
    }
    bool operator>(const Edge& e) const {
        return (weight != e.weight) ? (weight > e.weight) : (from > e.from);
    }
};

using Arc = Edge;
using Graph = vector<vector<Edge>>;
using DGraph = vector<vector<Arc>>;

using Tree = Graph;

// ?????????????????????????????¨????????????????????????!
using GArray = vector<Weight>;
using GMatrix = vector<GArray>;

// ??????4????????¢??°???????????°??????????????????????????§?????§?????????
void add_edge(Graph& g, int u, int v, Weight w = -1) {
    g[u].push_back(Edge(u, v, w));
    g[v].push_back(Edge(v, u, w));
}

void add_arc(DGraph& dg, int u, int v, Weight w = -1) {
    dg[u].push_back(Arc(u, v, w));
}

const int GM_INF = (1LL << 25);

void init_gmatrix(GMatrix& gm) {
    for (int u = 0; u < gm.size(); u++) {
        for (int v = 0; v < gm[u].size(); v++) {
            gm[u][v] = GM_INF;
        }
    }
}

void add_edge(GMatrix& gm, int u, int v, Weight w = -1) {
    gm[u][v] = w;
    gm[v][u] = w;
}

void add_arc(GMatrix& gm, int u, int v, Weight w = -1) {
    gm[u][v] = w;
}

namespace TSort {
    const int MAX_V = 1000010;

    DGraph dgraph;
    list<int> nodes;

    array<bool, MAX_V> used;
    array<int, MAX_V> indeg;

    void bfs(int s) {
        queue<int> que;
        que.push(s);
        used[s] = true;

        while (!que.empty()) {
            int v = que.front(); que.pop();
            nodes.push_back(v);

            for (Arc a : dgraph[v]) {
                indeg[a.to]--;
                if (indeg[a.to] == 0 && !used[a.to]) {
                    used[a.to] = true;
                    que.push(a.to);
                }
            }
        }
    }

    list<int>& tsort(DGraph& dg) {
        dgraph = dg;
        nodes.clear();
        used.fill(false);
        indeg.fill(0);

        for (int v = 0; v < dgraph.size(); v++) {
            for (Arc a : dgraph[v]) {
                indeg[a.to]++;
            }
        }

        for (int v = 0; v < dgraph.size(); v++) {
            if (indeg[v] == 0 && !used[v]) {
                bfs(v);
            }
        }
        return nodes;
    }
};

int main() {
    int v, e;
    cin >> v >> e;

    DGraph dgraph(v);

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        add_arc(dgraph, a, b);
    }

    auto nodes = TSort::tsort(dgraph);
    for (int node : nodes) {
        cout << node << endl;
    }

    return 0;
}