#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> Graph(N);
    vector<int> A(N - 1), B(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        A[i] = a, B[i] = b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);  //無向グラフ
    }

    vector<int> dist(N, -1);  // -1: 未訪問
    queue<P> que;

    dist[0] = 0;
    que.push(make_pair(0, -1));
    map<P, int> mp;
    int MAX = 1;
    while (!que.empty()) {
        int v = que.front().first;
        int col = que.front().second;
        que.pop();

        int nextcol = 0;
        for (int nv : Graph[v]) {
            if (dist[nv] != -1) continue;

            ++nextcol;
            if (nextcol == col) ++nextcol;
            dist[nv] = 1;
            mp[make_pair(min(v, nv), max(v, nv))] = nextcol;
            que.push(make_pair(nv, nextcol));
        }
        MAX = max(MAX, nextcol);
    }

    cout << MAX << endl;
    rep(i, N - 1) cout << mp[make_pair(A[i], B[i])] << endl;
}