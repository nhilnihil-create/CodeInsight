//
// Created by Hideaki Imamura on 2020-03-27.
//
# include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> l_l;
typedef pair<int, int> i_i;

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

# define EPS (1e-7)
# define INF (1e9)
# define PI (acos(-1))
//const ll mod = 1000000007;

int N, M, S, T;
vector<vector<int>> G;

int dijkstra(int s, int t) {
    vector<int> d(3 * N, INF);
    d[s] = 0;

    priority_queue<i_i, vector<i_i>, greater<i_i>> que;
    que.push(i_i(0, s));
    while (!que.empty()) {
        i_i p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (auto e : G[v]) {
            if (d[e] > d[v] + 1) {
                d[e] = d[v] + 1;
                que.push(i_i(d[e], e));
            }
        }
    }

    return d[t] == INF ? -3 : d[t];
}

int main() {
    cin >> N >> M;
    G.assign(3 * N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[3 * u + 0].push_back(3 * v + 1);
        G[3 * u + 1].push_back(3 * v + 2);
        G[3 * u + 2].push_back(3 * v + 0);
    }
    cin >> S >> T;
    S--;
    T--;
    cout << dijkstra(3 * S, 3 * T) / 3 << endl;
    return 0;
}