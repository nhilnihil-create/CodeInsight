#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n, i, j, k;
    long long ans = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            int t = __gcd(i, j);
            for (k = 1; k <= n; k++) {
                ans += __gcd(t, k);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
