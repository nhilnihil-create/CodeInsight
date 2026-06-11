#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;

int n, m, ans = -1;
vvi g;
vi vis;

void dfs(int i) {
    vis[i] = true;
    for (int j : g[i]) {
        if (!vis[j]) dfs(j);
    }
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    g.assign(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans << "\n";

	return 0;
}
