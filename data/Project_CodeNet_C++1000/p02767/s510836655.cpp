#include <bits/stdc++.h>
using namespace std;

void solve () {
    double n;
    cin >> n;
    vector<int> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double avg = round(sum / n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x = avg - a[i];
        ans += x * x;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
