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

int main() {
    ios::sync_with_stdio(false);
    int n, m, h[100005] = {}, u, v, z = 0;
    vector<int> g[100005] = {};
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    while (m--) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
    for (int i = 1; i <= n; i++) {
        bool y = 0;
        for (int j : g[i]) if (h[j] >= h[i]) y = 1;
        if (!y) z++;
    }
    cout << z;
}
