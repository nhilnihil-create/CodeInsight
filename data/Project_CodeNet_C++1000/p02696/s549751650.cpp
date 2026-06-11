#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b, n;

    cin >> a >> b >> n;

    if (n >= b - 1) {
        cout << a * (b - 1) / b - a * ((b - 1) / b);
    } else {
        cout << a * n / b - a * (n / b);
    }

    return 0;
}