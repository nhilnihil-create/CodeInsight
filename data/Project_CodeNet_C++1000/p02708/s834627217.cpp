#include <stdio.h>
long long mod = 1000000007;
long long f(long long x, long long y) {
    return ((x+y)*(y-x+1)/2)%mod;
}
int main() {
    int n, k;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = k; i <= n + 1; i++) {
        ans = (ans + f(n-i+1,n) - f(0,i-1)+1+mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
