#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0LL;
    int mx;
    cin >> mx;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        ans += max(0, mx - x);
        mx = max(x, mx);
    }
    cout << ans << '\n';
    return 0;
}