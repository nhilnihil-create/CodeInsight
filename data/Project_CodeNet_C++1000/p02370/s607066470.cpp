#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g (n);
    vector<int> chk (n, 0);
    rep (i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back (y);
        chk[y]++;
    }
    queue<int> q;
    rep (i, n) if (chk[i] == 0) q.push (i);

    vector<int> sortedvec;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto next : g[now]) {
            if (!chk[next]) continue;
            chk[next]--;
            if (!chk[next]) q.push (next);
        }
        sortedvec.push_back (now);
    }
    rep (i, n) cout << sortedvec[i] << "\n";
}
