#include <stdio.h>
#include <math.h>
 
int main(void) {
    int n, s;
    double sum = 0.0;
    double sum2 = 0.0;
 
    while (true) {
sum=sum2=0.0;
        scanf("%d", &n);
        if (n == 0) break;
 
        for (int i = 0; i < n; i++) {
            scanf("%d ", &s);
            sum += s;
            sum2 += s * s;
        }
 
        printf("%f\n", sqrt(sum2 / n - (sum / n) * (sum / n)));
    }
    return 0;
}