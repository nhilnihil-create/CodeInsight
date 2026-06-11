#include <stdio.h>
#define ll long long int

int main() {
    int n;
    scanf("%d", &n);
    ll sum = 0, a, flag = 0;
    while (n--) {
        scanf("%lld", &a);
        sum += a;
        (sum > 1000000000000000000) ? flag = 1 : sum;
    }
    flag ? printf("-1") : printf("%lld\n", sum);
    return 0;
}
