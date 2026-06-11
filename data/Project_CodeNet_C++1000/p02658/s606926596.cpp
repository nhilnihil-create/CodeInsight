#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long int arr[n], max = 1e18, prod = 1, flag = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        flag = arr[i] > max ? 1 : flag;
        prod *= arr[i];
        arr[i] ? max /= arr[i] : zero = 1;
    }
    if (zero) {
        printf("0\n");
    }
    else {
        flag ? printf("-1\n") : printf("%lld\n", prod);
    }
    return 0;
}
