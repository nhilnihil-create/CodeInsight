#include <bits/stdc++.h>
using namespace std;

void solve () {
    int k;
    cin >> k;
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            int x = __gcd(i, j);
            for (int l = 1; l <= k; l++) {
                ans += __gcd(x, l);
            }
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
