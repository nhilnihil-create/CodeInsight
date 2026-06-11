#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = 1e9 + 7;
int n, m;

vector<int> Map[200001];
set<pair<int, int>> s;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (s.count({ a,b }) == 0) {
            s.insert({ a,b });
            Map[a].push_back(b);
            Map[b].push_back(a);
        }
    }

    vector<bool> bfs_visited(n + 1, false);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        if (!bfs_visited[i]) {
            queue<int>q;
            q.push(i);
            bfs_visited[i] = true;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int j = 0; j < Map[cur].size(); j++) {
                    if (!bfs_visited[Map[cur][j]]) {
                        bfs_visited[Map[cur][j]] = true;
                        cnt++;
                        q.push(Map[cur][j]);
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
