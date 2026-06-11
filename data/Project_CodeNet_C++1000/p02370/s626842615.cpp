#include <bits/stdc++.h>
using namespace std;

const int WH = 0;
const int GR = 1;

int size_v, size_e;
vector<int> G[10100];
vector<int> indeg(10100, 0);
vector<int> color(10100, WH);
queue<int> Q;
vector<int> out;


void bfs(int s) {
    Q.push(s);
    color[s] = GR;
    for (; Q.empty() == false; ) {
        int u = Q.front(); Q.pop();
        out.push_back(u);

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (color[v] == WH) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    Q.push(v);
                    color[v] = GR;
                }
            }
        }
    }
}

int main() {
    cin >> size_v >> size_e;

    for (int i = 0; i < size_e; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        indeg[t]++;
    }

    for (int u = 0; u < size_v; u++) {
        if (indeg[u] == 0 && color[u] == WH) {
            bfs(u);
        }
    }

    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }

    return 0;
}

