#include<cstdio>
#include<cmath>

int main(){
    double a,b,c,deg,S;
    scanf("%lf%lf%lf",&a,&b,&deg);
    S = (0.5) * a * b * sin(M_PI * deg / 180);
    c = sqrt(a * a + b * b - 2 * a * b * cos(M_PI * deg / 180));
    printf("%.8lf\n%.8lf\n%.8lf\n",S,a + b + c,2 * S / a);

    return 0;
}
