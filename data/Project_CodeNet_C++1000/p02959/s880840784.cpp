#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long b; cin >> b;
        ans += min (a[i], b);
        b -= min (b , a[i]);
        ans += min (a[i + 1], b);
        a[i + 1] = max (0ll, a[i + 1] - b);
    }
    cout << ans;
    return 0;
}
