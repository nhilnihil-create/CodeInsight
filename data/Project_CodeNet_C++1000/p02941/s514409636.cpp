#include <bits/stdc++.h>

using namespace std;
#define int long long
priority_queue<pair<int, int>> q;
const int maxn = 2e5 + 5;
int n, m, b[maxn], a[maxn], pre[maxn], nxt[maxn];
signed main() {
    int i, j, k, ans = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &b[i]);
        q.push(make_pair(b[i], i));
    }

    for (i = 1; i <= n; ++i) {
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    pre[1] = n;
    nxt[n] = 1;
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (b[x] == a[x]) continue;
        int y = pre[x], z = nxt[x];
        if (b[x] - b[y] - b[z] < a[x]) {
            puts("-1");
            return 0;
        }
        k = b[x] - a[x];
        ans += k / (b[y] + b[z]);
        b[x] = (k % (b[y] + b[z])) + a[x];
        if (a[x] != b[x]) {
            q.push(make_pair(b[x], x));
        }
    }
    cout << ans << endl;
    return 0;
}