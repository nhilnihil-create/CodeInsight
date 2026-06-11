#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const double EPS = 1e-10;

int main() {
    int N;
    int X, Y;
    cin >> N >> X >> Y;
    X--, Y--;

    vector<vector<int>> to(N, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        to[i].push_back(i + 1);
        to[i + 1].push_back(i);
    }
    to[X].push_back(Y);
    to[Y].push_back(X);

    vector<vector<int>> dist2(N, vector<int>(N, INF));
    for (int start = 0; start < N; start++) {
        vector<int> dist(N, INF);
        dist[start] = 0;
        queue<int> q({start});
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            for (auto n : to[c]) {
                if (dist[n] != INF) continue;
                dist[n] = dist[c] + 1;
                q.push(n);
            }
        }

        for (int j = 0; j < N; j++) {
            dist2[start][j] = dist[j];
        }
    }
    // ddump(dist2);

    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cnt[dist2[i][j]]++;
        }
    }

    for (int k = 1; k < N; k++) {
        cout << cnt[k] << endl;
    }

    return 0;
}