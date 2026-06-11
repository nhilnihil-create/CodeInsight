
#include<cstdio>

int main(){
    double a, b, f;
    int r, x, c, d;
    
    scanf("%lf%lf",&a, &b);
    
    c = a;
    d = b;
    
    x = a / b;
    r = c % d;
    f = a / b;
    
    printf("%d %d %6f\n", x, r, f);
}