#include<bits/stdc++.h>
using namespace std;

class DSU {
private:
    int size;
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) : size(n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int a) {
        if (a != parent[a]) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    bool merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return false;

        if (rank[pa] < rank[pb]) {
            parent[pa] = parent[pb];
            rank[pb] += rank[pa];
        } else {
            parent[pb] = parent[pa];
            rank[pa] += rank[pb];
        }
        return true;
    }

};

int main() {
    int n, m, u, v;
    unordered_set<int> comp;

    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        dsu.merge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        comp.emplace(dsu.find(i));
    }

    cout << comp.size()-1;
    return 0;
}
