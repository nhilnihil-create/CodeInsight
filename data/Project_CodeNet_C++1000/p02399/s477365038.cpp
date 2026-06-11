#include<stdio.h>
\

int main(){
    int a, b;
    scanf("%d %d", &a, &b); 
    int d = a / b; 
    int r = a % b;
    double f = 1.00 * a / b; 
    printf("%d\n", d);
    printf("%d\n", r);
    printf("%.6lf\n", f);

    return 0;
}