#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    queue<int> que;
    vector<int> pre(n, -1);
    vector<int> dist(n, -1);

    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nv : g[v]) {
            if (dist[nv] != -1) {
                continue;
            }

            dist[nv] = dist[v] + 1;
            pre[nv] = v;
            que.push(nv);
        }

    }

    cout << "Yes" << endl;
    rep(i,n) {
        if (i == 0) {
            continue;
        }
        cout << pre[i]+1 << endl;
    }
    return 0;
}