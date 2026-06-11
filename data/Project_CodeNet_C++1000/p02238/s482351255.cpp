#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
//#include "../cxx-prettyprint/prettyprint.hpp"

int timer = 0;
std::unordered_map<int, std::vector<int>> Adj;
std::set<int> nodes_unvisited;
std::unordered_map<int, int> discovered_time;
std::unordered_map<int, int> finished_time;

int dfs(int u) {
    nodes_unvisited.erase(u);
    discovered_time[u] = ++timer;
    for (int v : Adj[u]) {
        if (nodes_unvisited.find(v) != nodes_unvisited.end()) {
            dfs(v);
        }
    }
    finished_time[u] = ++timer;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i ++) {
        int u, k;
        std::cin >> u >> k;
        std::vector<int> V(k);
        for (auto& v : V) {
            std::cin >> v;
        }
        Adj[u] = V;
    }

    for (int i = 1; i <= n; i ++) {
        nodes_unvisited.insert(i);
    }

    while (!nodes_unvisited.empty()) {
        int u = *nodes_unvisited.begin();
        dfs(u);
    }

    for (int i = 1; i <= n; i ++) {
        std::cout << i << " " << discovered_time[i]
            << " " << finished_time[i] << std::endl;
    }
}

