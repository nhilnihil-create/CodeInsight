#include <bits/stdc++.h>
using namespace std;

void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (k >= n) {
        cout << 0;
        return;
    }
    sort (a.rbegin(), a.rend());
    for (int i = 0; i < k; i++) {
        sum -= a[i];
    }
    cout << sum;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
