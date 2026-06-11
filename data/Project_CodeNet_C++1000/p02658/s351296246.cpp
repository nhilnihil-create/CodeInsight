#include <stdio.h>

int main() {
    long long int r[100005], n, calc = 1;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &r[i]);
    }
    for (int i = 0; i < n; i++) {
        if (r[i] == 0) {
            printf("0");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (r[i] <= (1000000000000000000 / calc)) {
            calc *= r[i];
        } else {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", calc);
}