#include <iostream>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
const LL MOD = 998244353;
int n, d[N], mx;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        int x; scanf("%d", &x);
        if (i == 1 && x != 0) return !printf("0\n");
        d[x] ++; mx = max(mx, x);
    }
    if (d[0] > 1 || d[0] == 0) return !printf("0\n");
    LL ans = d[0];
    for (int i = 1; i <= mx; i ++) {
        if (d[i] == 0) return !printf("0\n");
        for (int j = 1; j <= d[i]; j ++) {
            ans = ans * d[i-1] % MOD;
        }
    }
    cout << ans << endl;
}
