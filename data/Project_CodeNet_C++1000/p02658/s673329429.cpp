#include <stdio.h>
#define ll long long int

int main() {
    int n;
    scanf("%d", &n);
    ll arr[n], max = 1e18, prod = 1, flag = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        arr[i] > max ? flag = 1 : flag = flag;
        prod *= arr[i];
        arr[i] ? max /= arr[i] : zero = 1;
    }
    if (zero) {
        puts("0");
    }
    else {
        flag ? printf("-1\n") : printf("%lld\n", prod);
    }
    return 0;
}
