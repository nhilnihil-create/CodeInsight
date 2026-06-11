#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int MAX = 100;
int cost[MAX][MAX];
int n;

void dijkstra() {
    int d[n];
    bool seen[n] = {};
    rep (i, n) { d[i] = inf; }
    d[0] = 0;
    while (1) {
        int minc = inf, now;
        rep (i, n) {
            if (minc > d[i] && !seen[i]) {
                minc = d[i];
                now = i;
            }
        }
        seen[now] = 1;
        if (minc == inf) break;
        rep (i, n) {
            if (cost[now][i] != inf && !seen[i]) {
                if (d[i] > cost[now][i] + d[now]) {
                    d[i] = cost[now][i] + d[now];
                }
            }
        }
    }
    rep (i, n) { cout << i << " " << d[i] << "\n"; }
    return;
}

int main() {
    cin >> n;
    rep (i, n) rep (j, n) cost[i][j] = inf;
    rep (i, n) {
        int now, k, next, c;
        cin >> now >> k;
        rep (i, k) {
            cin >> next >> c;
            cost[now][next] = c;
        }
    }
    dijkstra();
}
