#include <bits/stdc++.h>
using namespace std;

#pragma optimize("O3")

#define int long long

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int x;
    cin >> x;

    int cur = 100;

    int index = 0;

    while (true) {
        index += 1;
        cur = (cur / 100) + cur;
        if (cur >= x) {
            cout << index;
            break;
        }
    }

    return 0;
}