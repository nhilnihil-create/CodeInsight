#include <algorithm>
#include <cassert>
const int MaxNode = 100;

struct UnionFind {
    int node_num;
    int parent[MaxNode];
    int weight = 0;
    
    UnionFind(int node_num) : node_num(node_num) {
        std::fill(parent, parent + node_num, -1);
    }
    
    int root(int u) {
        return parent[u] < 0 ? u : parent[u] = root(parent[u]);
    }
    
    bool find(int u, int v) {
        return root(u) == root(v);
    }
    
    bool unite(int u, int v, int cost) {
        if ((u = root(u)) == (v = root(v))) {
            return false;
        } else {
            if(parent[u] > parent[v]) {
                std::swap(u, v);
            }
            parent[u] += parent[v];
            parent[v] = u;
            weight += cost;
            return true;
        }
    }
};
template <typename T>
struct Edge {
    
    Edge() = default;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
    
    Edge(const Edge&) = default;
    Edge& operator=(const Edge&) = default;
    Edge& operator=(Edge&&) = default;
    
    
    int from;
    int to;
    T cost;
};

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	UnionFind uf(n);
	
	std::vector<Edge<int>> edges(n);
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			int dist;
			cin >> dist;
			
			if(i != j && dist != -1) {
				edges.emplace_back(i, j, dist);
			}
		}
	}
	
	std::sort(edges.begin(), edges.end(), [](Edge<int> a, Edge<int> b){return a.cost < b.cost;});

	for (auto& e : edges) {
        if (!uf.find(e.from, e.to)) {
            uf.unite(e.from, e.to, e.cost);
        }
    }
    
    cout << uf.weight << endl;
	return 0;
}