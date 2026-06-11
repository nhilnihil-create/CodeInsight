#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <string.h>
#include <map>
#include <iomanip>
#include <time.h>
using namespace std;
typedef long long ll;

int n, m;
bool vis[100010] = {};
vector<int> G[100010], tp;

void dfs(int v) {
    if (!vis[v]) {
        vis[v] = 1;
        for (int i = 0; i < G[v].size(); i++) {
            dfs(G[v][i]);
        }
        tp.push_back(v);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    bool t[n + 5] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            t[G[i][j]] = 1;
        }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (!t[i]) {
            root = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) dfs(i);
    reverse(tp.begin(), tp.end());

    for (int i = 0; i < n; i++) cout << tp[i] << endl;

}

