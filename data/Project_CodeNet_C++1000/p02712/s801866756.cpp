#include <stdio.h>
 
int main() {
    long long int a, b = 0;
    scanf("%lld", &a);
    for (int i = 1; i <= a; i++) {
        if ((i % 3) == 0 || (i % 5) == 0) {
            b = b;
        } else {
            b += i;
        }
    }
    printf("%lld", b);
}