#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y; cin >> x >> y;
    if (x == 1 && y == 1) {
        cout << 1000000 << '\n';
    }
    else {
        int ans = 0;
        if (x <= 3) ans += 100000*(4-x);
        if (y <= 3) ans += 100000*(4-y);
        cout << ans << '\n';
    }
}

