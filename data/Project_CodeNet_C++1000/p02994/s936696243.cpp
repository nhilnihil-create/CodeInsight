#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, l;
    cin >> n >> l;

    int t_zero = INT_MAX;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = l + i - 1;
        ans += t;
        if (abs(t) < abs(t_zero)) {
            t_zero = t;
        }
    }
    ans -= t_zero;
    cout << ans << endl;
}
