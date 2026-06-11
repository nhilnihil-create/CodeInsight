#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n + 1, 0);
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
    ll ans = 1e18;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
    }
    cout << ans << endl;
    return 0;
}