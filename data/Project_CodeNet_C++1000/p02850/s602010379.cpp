#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;

struct edge {
    edge() : link_to(0), color(0) {}
    edge(int t, int c) : link_to(t), color(c) {}
    int link_to;
    int color;
};

void dfs(int node, std::vector<std::map<i64, edge>>& graph, int cl_max, const edge& from, bool root = false) {
    int used_watermark{0};

    for (auto& kv : graph[node]) {
        edge& e = kv.second;
        if (root) {
            dfs(e.link_to, graph, cl_max, e);
        }
        else if (e.color==0) {
            if (++used_watermark == from.color) {
                ++used_watermark;
            }
            if (used_watermark > cl_max) {
                cout << "  " << node << " " << e.link_to;
            }
            e.color = used_watermark;
            graph[e.link_to][node].color = used_watermark;
            dfs(e.link_to, graph, cl_max, e);
        }
    }
}

int main(int argc, char **argv) {
    i64 n;
    cin >> n;

    std::vector<std::map<i64, edge>> graph(n);
    std::vector<P> input;

    for (int i=0; i<n-1; ++i) {
        i64 a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].insert(make_pair(b, edge(b, 0)));
        graph[b].insert(make_pair(a, edge(a, 0)));
        input.push_back(make_pair(a,b));
    }

    i64 max_{0}, root;
    for (size_t i=0; i<n; ++i) {
        if (graph[i].size() > max_) {
            max_ = graph[i].size();
            root = i;
        }
    }

    int i=1;
    for (auto& kv :graph[root]) {
        edge& e = kv.second;
        e.color = i;
        graph[e.link_to][root].color = i;
        ++i;
    }

    dfs(root, graph, max_, edge(), true);

    cout << max_ << endl;
    for (auto p : input) {
        cout << graph[p.first][p.second].color << endl;
    }

    return 0;
}