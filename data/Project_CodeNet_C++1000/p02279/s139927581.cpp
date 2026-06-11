#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int par[100100], l[100100], r[100100], d[100100]; //lは一番左の子、rはすぐ隣の兄弟、dは深さ

void print (int u) {
    cout << "node " << u << ": parent = " << par[u] << ", depth = " << d[u];
    if (par[u] == -1) {
        cout << ", root, [";
    } else if (l[u] == -1) {
        cout << ", leaf, [";
    } else {
        cout << ", internal node, [";
    }
    for (int i = 0, cur = l[u]; cur != -1; i++, cur = r[cur]) {
        if (i) cout << ", ";
        cout << cur;
    }
    cout << "]\n";
}

int setD (int u, int now) {
    d[u] = now;
    if (l[u] != -1) setD (l[u], now + 1);
    if (r[u] != -1) setD (r[u], now);
}

int main() {
    int n;
    cin >> n;
    rep (i, n) par[i] = l[i] = r[i] = -1;
    int cur, k;
    rep (i, n) {
        cin >> cur >> k;
        int prev;
        rep (j, k) {
            int next;
            cin >> next;
            par[next] = cur;
            if (j == 0) l[cur] = next;
            if (j > 0) r[prev] = next;
            prev = next;
        }
    }
    int root;
    rep (i, n) {
        if (par[i] == -1) root = i;
    }
    setD (root, 0);
    rep (i, n) print (i);
}

