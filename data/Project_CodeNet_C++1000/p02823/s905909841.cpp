#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;

int main(void)
{
    ll ans = 0;

    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);

    if ((b - a) % 2)
        ans = min(a - 1, n - b) + 1 + (b - a - 1) / 2;
    else
        ans = (b - a) / 2;

    printf("%lld\n", ans);

    return 0;
}