#include <bits/stdc++.h>
 
#define loop(n, i) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

int C[100][100] = {};
int vis[100][100] = {};

int dfs(int i, int j)
{
    int d[] = {1, 0, -1};
    if (!vis[i][j] && C[i][j]) {
        vis[i][j] = 1;
        loop (3, x) loop (3, y) dfs(i + d[x], j + d[y]);
    }
}

int main()
{
    while (1) {
        fill(C[0], C[99]+100, 0);
        fill(vis[0], vis[99]+100, 0);

        int w, h; cin >> w >> h;
        if (!w && !h) break;
        loop (h, i) loop (w, j) cin >> C[i+1][j+1];

        int ans = 0;
        loop (h, i) loop (w, j) {
            if (vis[i+1][j+1] || !C[i+1][j+1]) continue;
            ans++;
            dfs(i+1, j+1);
        }
        cout << ans << endl;
    }
    return 0;
}