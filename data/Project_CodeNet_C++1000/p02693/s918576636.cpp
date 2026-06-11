#include <bits/stdc++.h>
using namespace std;

#pragma optimize("O3")

#define int long long

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b, c;
    cin >> a >> b >> c;

    for (; b <= c; ++b) {
        if (b % a == 0) {
            cout << "OK";
            return 0;
        }
    }

    cout << "NG";

    return 0;
}