#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    long long ans;
    long long t;
    cin >> t;
    ans += t;
    for (int i = 1; i < n - 1; i++) {
        long long x;
        cin >> x;
        ans += min (x, t);
        t = x;
    }
    ans += t;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
