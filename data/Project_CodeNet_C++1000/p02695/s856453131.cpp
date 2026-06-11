#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int n, m, q;
int a[51], b[51], c[51], d[51];
int A[11];
ll ans = 0;

void dfs(int k) {
    if (k == n) {
        ll sum = 0;
        for(int i = 1; i <= q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) {
                sum += d[i];
            }
        }
        ans = max(ans, sum);
    } else {
        for (int i = A[k]; i <= m; i++) {
            A[k+1] = i;
            dfs(k+1);
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    A[0] = 1;
    dfs(0);
    cout << ans << endl;
}