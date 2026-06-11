#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 2e5 + 5;
long long A[N] = {}, B[N] = {};
int n, m;
int bs(long long k) {
    int l = 1, r = m, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (B[mid] <= k) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        B[i] += B[i - 1];
    }
    int ans = 0;
    for (int i = 0; i <= n && A[i] <= k; i++) {
        ans = max(ans, i + bs(k - A[i]));
    }
    cout << ans << '\n';
}