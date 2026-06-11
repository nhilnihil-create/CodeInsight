#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 2005;

LL f[N][N];
int main() {
    int n;
    cin >> n;
    LL ans = 0;
    f[0][0] = 1;
    for (int i = 1; i <= n / 3; i++) {
        LL now = 0;
        for (int j = 3; j <= n; j++) {
            now += f[i - 1][j - 3];
            f[i][j] = (f[i][j] + now) % mod;
        }
        ans += f[i][n];
    }
    cout << ans % mod << endl;
    return 0;
}
