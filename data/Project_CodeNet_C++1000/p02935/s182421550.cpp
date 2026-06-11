#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n;
    cin >> n;
    vector<long double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    long double ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = (ans + a[i]) / 2;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
