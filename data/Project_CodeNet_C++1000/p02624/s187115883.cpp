#include <stdio.h>
#include <stdint.h>
typedef int64_t i64;

int main(void){
    i64 n, sum = 0;
    scanf("%lld", &n);
    for(i64 i=1; i<=n; i++) sum += (i + (n/i)*i)*(n/i)/2;
    printf("%lld", sum);
    return 0;
}