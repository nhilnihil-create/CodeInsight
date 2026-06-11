// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

struct Edge {
    int id;
    int to;
    int color;
    Edge(int i, int t, int c) : id(i), to(t), color(c) { }
};
using Graph = vector<vector<Edge>>;

int N;

void bfs(Graph& G, int s) {
    queue<int> que;
    que.push(s);

    while (!que.empty()) {
        vector<bool> colors(N-1, false);  // 最大でもN-1色あればOK。
        
        int v = que.front();
        que.pop();

        // cout << v << endl;
        
        for (Edge& next_e : G[v]) {
            if (next_e.color != -1) {
                colors[next_e.color] = true;
            }
        }

        for (Edge& next_e : G[v]) {
            if (next_e.color == -1) {
                int color = -1;
                rep(i, N-1) {
                    if (colors[i] == false) {
                        color = i;
                        colors[i] = true;
                        break;
                    }
                }
                next_e.color = color;
                // 逆向きの色も塗る。
                for (Edge &ne : G[next_e.to]) {
                    if (ne.to == v) ne.color = color;
                }

                que.push(next_e.to);
            }
        }
    }
}

int main() {
    cin >> N;

    Graph G(N);
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({i, b, -1});
        G[b].push_back({i, a, -1});
    }

    bfs(G, 0);

    int K = 0;
    vector<P> ans;
    rep(i, N) {
        for (auto next_e : G[i]) {
            K = max(K, next_e.color);
            ans.push_back({next_e.id, next_e.color});
        }
    }

    // sort(ans.begin(), ans.end());

    map<int, int> mp;
    rep(i, N) {
        for (auto next_e : G[i]) {
            mp[next_e.id] = next_e.color;
        }
    }

    // cout << "here?" << endl;
    cout << K + 1 << endl;
    // for (auto a : ans) {
    //     cout << a.second + 1 << endl;
    // }

    for (auto p : mp) {
        cout << p.second + 1 << endl;
    }
}