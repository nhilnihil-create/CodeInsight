#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int m, d;
    cin >> m >> d;
    int ans = 0;
    for (int d1 = 2; d1 <= 9; d1++) {
        for (int d10 = 2; d10 <= 9; d10++) {
            if (d10 * 10 + d1 > d) continue;
            if (d10 * d1 <= m) ans++;
        }
    }
    cout << ans << endl;
}
