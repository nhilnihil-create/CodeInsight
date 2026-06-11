#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using pii = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    auto encode = [&](int i, int j) { return i * N + j; };
    unordered_map<int, vector<int>> g;
    unordered_map<int, int> indegree;
    REP(i, N) {
        int u, v;
        REP(j, N - 1) {
            int A;
            cin >> A;
            --A;
            v = encode(min(i, A), max(i, A));
            if (j) {
                g[u].push_back(v);
                ++indegree[v];
            }
            u = v;
        }
    }

    queue<pii> q;
    REP(i, N) FOR(j, i + 1, N) {
        int v = encode(i, j);
        if (indegree[v] == 0) {
            q.emplace(v, 1);
        }
    }

    int result = 0;
    REP(_, N * (N - 1) / 2) {
        if (q.empty()) {
            result = -1;
            break;
        }
        int u, depth;
        tie(u, depth) = q.front();
        q.pop();
        result = max(result, depth);
        for (int v: g[u]) {
            --indegree[v];
            if (indegree[v] == 0) {
                q.emplace(v, depth + 1);
            }
        }
    }

    cout << result << endl;

    return 0;
}