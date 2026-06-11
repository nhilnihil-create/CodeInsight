#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

vector<int> g[200005];
int d[200005];

void dfs(int x, int p) {
    for (int i : g[x]) if (i != p) {
        d[i] += d[x];
        dfs(i, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, u, v;
    cin >> n >> q;
    for (int i = 1; i < n; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    while (q--) cin >> u >> v, d[u] += v;
    dfs(1, 1);
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}
