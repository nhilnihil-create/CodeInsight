#include <stdio.h>
#include <string.h>

int main() {
    long long int n, total = 0;
    scanf("%lld", &n);


    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            total = total + i;
        }
    }

    printf("%lld", total);
    

    return 0;
}