#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

vector<int> g[N];
int dis[N];
int sol = 0;
int col[N];

void bfs(int a) {
    memset(dis, 63, sizeof(dis));
    memset(col, 0, sizeof(col));
    queue<int> q;

    dis[a] = 0;
    q.push(a);
    while (q.size()) {
        int curr = q.front();
        q.pop();

        int c = 1;
        for (int b : g[curr]) {
            if (dis[b] > dis[curr] + 1) {
                dis[b] = dis[curr] + 1;
                q.push(b);

                if (c == col[curr]) ++c;
                col[b] = c++;

                sol = max(sol, (int) g[curr].size());
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    int id[n + 1];

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        id[i] = b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(1);

    cout << sol << endl;
    for (int i = 1; i < n; ++i) {
        cout << col[id[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}
