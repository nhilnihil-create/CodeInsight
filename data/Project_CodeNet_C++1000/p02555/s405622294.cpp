#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 2005;

int c[N][N];
int main() {
    for (int i = 0; i <= 2000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    int n;
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n / 3; i++) {
        ans += c[n - i * 2 - 1][i - 1];
    }
    cout << ans % mod << endl;
    return 0;
}
