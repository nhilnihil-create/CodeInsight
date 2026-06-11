#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

using ll = long long;

static const int MAX = 100000;
vector<vector<int>> G;
int color[MAX];

void input_graph(int m) {
    int s, t;
    rep(i, m) {
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
}

void init_graph(int n) {
    rep(i, n) {
        vector<int> vec;
        G.push_back(vec);
    }
}
void bfs(int s, int color_id) {
    queue<int> que;
    que.push(s);
    color[s] = color_id;
    while(que.size() > 0) {
        int u = que.front();
        que.pop();
        rep(i, G[u].size()) {
            int v = G[u][i];
            if(color[v] == -1) {
                que.push(v);
                color[v] = color_id;
            }
        }
    }
}

void color_assign(int n) {
    int color_id = 1;
    rep(i, n) { color[i] = -1; }
    rep(i, n) {
        if(color[i] == -1) {
            bfs(i, color_id++);
        }
    }
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, m, q, s, t;
    cin >> n >> m;
    init_graph(n);
    input_graph(m);
    color_assign(n);
    cin >> q;
    rep(i, q) {
        scanf("%d %d", &s, &t);
        if(color[s] == color[t]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
