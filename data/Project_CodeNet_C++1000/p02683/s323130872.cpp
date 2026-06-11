#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m, x, c[N], a[N][N], p[N], ans = 0x3f3f3f3f;
void dfs(int s, int price) {
    if (s == n + 1) {
        for (int i = 1; i <= m; i++)
            if (p[i] < x)
                return;
        ans = min(ans, price);
        return;
    }
    dfs(s + 1, price);
    for (int i = 1; i <= m; i++)
        p[i] += a[s][i];
    dfs(s + 1, price + c[s]);
    for (int i = 1; i <= m; i++)
        p[i] -= a[s][i];
}
int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    dfs(1, 0);
    if (ans > 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}