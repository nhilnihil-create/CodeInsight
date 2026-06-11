#include <stdio.h>
#include <algorithm>
using namespace std;
long long mod = 1000000007;
long long f[100010];
long long get_pow(long long x, long long k, long long mod) {
    long long res = 1;
    while (k) {
        if (k & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        k >>= 1;
    }
    return res;
}
int main() {
    int n, k, i, j;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= k; i++) {
        f[i] = get_pow(k / i, n, mod);
    }
    for (i = k; i >0; i--) {
        for (j = i+i; j <= k; j += i) f[i] = (f[i]-f[j]+mod) % mod;
    }
    for (i = 1; i <= k; i++) {
        ans = (ans + i * f[i]) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
