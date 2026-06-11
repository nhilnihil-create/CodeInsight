#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
int dis[MAX][3];
int n, m;

void bfs(int source) {
    memset(dis, -1, sizeof dis);
    queue<ii> q;
    q.emplace(source, 0);
    dis[source][0] = 0;
    while (!q.empty()) {
        ii cur = q.front();
        q.pop();
        int u, p;
        tie(u, p) = cur;
        for (auto &each : adj[u]) {
            ii nxt = ii(each, (p + 1) % 3);
            if (dis[nxt.first][nxt.second] == -1) {
                dis[nxt.first][nxt.second] = dis[u][p] + 1;
                q.push(nxt);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    fori (i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    bfs(s);
    int ans = dis[t][0];
    if (ans != -1) ans /= 3;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

