#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for (int d = 22; d <= D; d++) {
        int d1 = d % 10;
        int d10 = d / 10;
        if (d1 >= 2 && d1 * d10 <= M) ans++;
    }

    cout << ans << endl;
    return 0;
}
