#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int x, y; cin >> x >> y;

    int ans = 0;

    if (x == 1) ans += 300000;
    if (x == 2) ans += 200000;
    if (x == 3) ans += 100000;

    if (y == 1) ans += 300000;
    if (y == 2) ans += 200000;
    if (y == 3) ans += 100000;

    if (x == 1 && y == 1) ans += 400000;

    cout << ans << endl;
}