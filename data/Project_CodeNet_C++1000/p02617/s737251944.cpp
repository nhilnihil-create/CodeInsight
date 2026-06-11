#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, u, v;
    ll d[200005] = {}, z = 0;
    vector<int> g[200005] = {};
    cin >> n;
    for (int i = 1; i < n; i++) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; i++) {
        d[i] = d[i - 1] + i;
        for (int j : g[i]) if (j < i) d[i] -= j;
        z += d[i];
    }
    cout << z;
}
