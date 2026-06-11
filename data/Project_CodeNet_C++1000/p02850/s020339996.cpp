#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define FOR(i, m, n) for(int i = (int)m; i < (int)n; i++)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> edges(N);
    vector<pair<int, int>> E;

    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].emplace_back(b - 1);
        edges[b - 1].emplace_back(a - 1);
        E.emplace_back(make_pair(a - 1, b - 1));
    }

    int used[100000] = {};
    int color[100000] = {};
    map<pair<int, int>, int> mc;
    int ans = 0;

    queue<int> que;
    que.emplace(0);
    used[0] = 1;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        int col = 1;
        for (int c : edges[v]) {
            if (used[c] == 1) continue;
            if (col == color[v]) col++;
            color[c] = col;
            mc[make_pair(v, c)] = col;
            mc[make_pair(c, v)] = col;
            ans = max(ans, col);
            col++;
            que.emplace(c);
        }
        used[v] = 1;
    }

    cout << ans << endl;
    REP(i, N - 1) {
        cout << mc[E[i]] << endl;
    }

    return 0;
}