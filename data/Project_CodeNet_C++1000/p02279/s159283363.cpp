#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tree {
    int n; // number of nodes
    vector<int> parent; //parent
    vector<vector<int>> g; //graph for the tree
    vector<int> depth; //depth
    
    Tree(int n): n(n) {
       parent.assign(n, -2);
       g.assign(n, vector<int>());
       depth.assign(n, 0);
    }
    
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
        parent[v] = u;
    }
    
    void dfs(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        for (int v : g[u]) {
           if (v != p && parent[v] == -2) {
               dfs(v, u, d + 1);
           } 
        }    
    }

    string formatChildren(int i){
        string children = "[";
        for (int v : g[i]) {
            if (v != parent[i]) {
                if (children.size() > 1) {
                    children += ", "; 
                }
                children += to_string(v);
            }
        }
        children += "]";
        return children;
    }

    string formatNodeType(int i){
        string type = "";
        if (parent[i] == -1) {
            type = "root";
        } else if (g[i].size() > 1) {
            type = "internal node";
        } else {
            type = "leaf";
        }
        return type;
    }
    
    void solve() {
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -2) {
                root = i;
                break;
            }
        }
        parent.assign(n, -2);
        dfs(root, -1, 0);
        
        for (int i = 0; i < n; i++) {
            printf("node %d: parent = %d, depth = %d, %s, %s\n", 
                    i, parent[i], depth[i], formatNodeType(i).c_str(), 
                    formatChildren(i).c_str());
        }
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            tree.addEdge(u, v);
        }
    }
    tree.solve();
    
    return 0;
}