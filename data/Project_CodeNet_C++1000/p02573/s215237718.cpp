#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int maxn = 2e5 + 5;
typedef long long ll;
typedef uint64_t HT;
const int mod = 1e9 + 7;
int pre[N], sum[N];
int find(const int &x) {
    return x == pre[x] ? x : pre[x] = find(pre[x]);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
        sum[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (xx != yy) {
            pre[xx] = yy;
            sum[yy] = sum[yy] + sum[xx];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) ans = max(ans, sum[i]);
    }
    cout << ans << "\n";
    return 0;
}