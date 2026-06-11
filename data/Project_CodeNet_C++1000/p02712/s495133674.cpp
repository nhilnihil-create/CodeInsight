#include <stdio.h>

int main() {
    long long int n, s = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        if ((i % 3) == 0 || (i % 5) == 0) {
            s = s;
        } else {
            s += i;
        }
    }
    printf("%lld", s);
}