// F
// DeP
#include <cstdio>

typedef long long LL;
const int MAXN = 5e3+5;

int K, q;
LL d[MAXN], A[MAXN];

int main() {
    // input
    scanf("%d%d", &K, &q);
    for (int i = 0; i < K; ++i) scanf("%lld", d+i);
    // solve
    while (q--) {
        static int n, x, m;
        scanf("%d%d%d", &n, &x, &m);
        --n;
        int eq =  0;
        for (int i = 1; i <= K; ++i) {
            A[i] = A[i-1] + d[i-1] % m;
            if (d[i-1] % m == 0) eq += (n / K) + (i <= n % K);
        }
        LL sum = A[K] * (n / K) + A[n % K] + x % m;
        printf("%lld\n", n - eq - sum / m);
    }
    return 0;
}