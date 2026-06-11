#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve() {
    int n, m; cin >> n >> m;
    vector<int> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        if (graph.find(x) == graph.end()) {
            vector<int> v;
            graph[x] = v;
        }
        if (graph.find(y) == graph.end()) {
            vector<int> v;
            graph[y] = v;
        }
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
    
    int res{0};
    for (int i = 1; i <=n; ++i) {
        bool good = true;
        for (int nei : graph[i]) {
            if (H[nei - 1] >= H[i - 1]) {
                good = false;
                break;
            }
        }
        if (good) {
            res++;
        }
    }
    
    return res;
}

int main() {
	cout << solve() << "\n";
}
