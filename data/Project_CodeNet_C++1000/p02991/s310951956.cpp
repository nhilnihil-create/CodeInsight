#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using large = long long;

struct Node {
    int v;
    int distance;

    friend bool operator<(const Node a, const Node b) { return a.distance < b.distance; }
};

static Node extract(vector<Node> &nodes) {
    int index = 0;
    int min_distance = nodes[0].distance;
    for (int i = 1; i < nodes.size(); i++) {
        if (nodes[i].distance < min_distance) {
            min_distance = nodes[i].distance;
            index = i;
        }
    }

    if (index + 1 != nodes.size()) {
        swap(nodes[index], nodes.back());
    }
    auto node = nodes.back();
    nodes.pop_back();
    return node;
}

static large distance(int start, int goal, const std::vector<vector<int>> &connected_from) {
    const auto n = connected_from.size();
    auto touched = vector<char>(n);
    auto closed = vector<char>(n);
    auto nodes = vector<Node>();

    nodes.push_back(Node{start, 0});
    touched[start] = true;

    while (!nodes.empty()) {
        // auto node = *nodes.begin();
        // nodes.erase(nodes.begin());
        auto node = extract(nodes);
        closed[node.v] = true;

        if (node.v == goal) {
            return node.distance;
        }

        for (auto u : connected_from[node.v]) {
            if (closed[u])
                continue;
            if (!touched[u]) {
                touched[u] = true;
                nodes.push_back(Node{u, node.distance + 1});
                continue;
            }
            auto itr = find_if(nodes.begin(), nodes.end(), [u](auto &n) { return n.v == u; });
            if (itr != nodes.end()) {
                if (node.distance + 1 < itr->distance) {
                    // nodes.erase(itr);
                    // nodes.insert(Node{u, node.distance + 1});
                    itr->distance = node.distance + 1;
                }
            }
        }
    }

    return -3;
}

int main() {
    int n, m;
    cin >> n >> m;

    auto connected_from = vector<vector<int>>(n * 3);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        connected_from[3 * u + 0].push_back(3 * v + 1);
        connected_from[3 * u + 1].push_back(3 * v + 2);
        connected_from[3 * u + 2].push_back(3 * v + 0);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;

    cout << distance(3 * s, 3 * t, connected_from) / 3;
    return 0;
}
