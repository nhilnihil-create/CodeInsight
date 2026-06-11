#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> deg(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[b].push_back(a);
        deg[a]++;
    }

    queue<int> que;
    for (int v = 0; v < N; v++) {
        if (deg[v] == 0) que.push(v);
    }

    vector<int> order;
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        order.push_back(v);

        for (auto nv : G[v]) {
            deg[nv]--;
            if (deg[nv] == 0) que.push(nv);
        }
    }

    reverse(order.begin(), order.end());
    for (int v : order) {
        cout << v << "\n";
    }
    return 0;
}
