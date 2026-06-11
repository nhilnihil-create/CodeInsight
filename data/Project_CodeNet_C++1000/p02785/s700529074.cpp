#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];
    sort(as.begin(), as.end());
    long long ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += as[i];
    }
    cout << ans << endl;
}
