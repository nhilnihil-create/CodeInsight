#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    long long asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        bsum += b[i];
    }

    int ans = 0, bi = m;
    for (int ai = 0; ai <= n; ai++) {
        if (ai > 0) asum += a[ai-1];
        if (asum > k) break;
        for (; bi >= 0; bi--) {
            if (asum+bsum <= k || bi == 0) {
                ans = max (ans, ai+bi);
                break;
            }
            else bsum -= b[bi-1];
        }
    }
    cout << ans << endl;
}