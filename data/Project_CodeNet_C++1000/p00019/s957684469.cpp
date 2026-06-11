#include <stdio.h>

int main() {
    long long n = 0;
    long long result = 1;
    scanf("%d", &n);

    for (long long i = n; 1 < i; --i) {
        result *= i;
    }

    printf("%lld\n", result);

    return 0;
}