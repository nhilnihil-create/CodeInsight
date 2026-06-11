#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int a[4] = {300000, 200000, 100000, 0};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y, ans = 0;
    cin >> x >> y;
    --x, --y;
    if (x > 3) x = 3;
    if (y > 3) y = 3;
    ans += a[x] + a[y];
    if (!x && !y) ans += 400000;
    cout << ans << '\n';
}