#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

vector<pii> g[100005];
int z[100005], y = 0;

void dfs(int x, int p, int q) {
    int c = 1;
    if (q == 1) c = 2;
    for (pii i : g[x]) if (i.first != p) {
        z[i.second] = c;
        y = max(y, c);
        dfs(i.first, x, c);
        c++;
        if (c == q) c++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, u[100005] = {}, v[100005] = {};
    cin >> n;
    for (int i = 1; i < n; i++) cin >> u[i] >> v[i], g[u[i]].push_back({v[i], i}), g[v[i]].push_back({u[i], i});
    dfs(1, 1, 0);
    cout << y << '\n';
    for (int i = 1; i < n; i++) cout << z[i] << '\n';
}
