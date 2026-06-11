#include <stdio.h>

int main()

{
    long long int a;
    scanf("%lld", &a);
    printf("%lld", a + (a * a) + (a * a * a));

    return 0;
}