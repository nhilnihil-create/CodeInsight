#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;
int *color;
vector<int> L;

void visit(int u);

void toporogical_sort(int s) {
    color[s] = 1;
    for (int i = 0; i < G[s].size(); i++) {
        int u = G[s][i];
        if (color[u] == 0) {
            visit(u);
        }
    }
    L.push_back(s);
}

void visit(int u) {
    color[u] = 1;
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (color[v] == 0) {
            visit(v);
        }
    }
    L.push_back(u);
}

int main() {
    int n, m; cin >> n >> m;
    G.resize(n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
    }

    color = new int[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) 
            toporogical_sort(i);
    }

    for (int i = n-1; i >= 0; i--)
        cout << L[i] << endl;
    return 0;
}
