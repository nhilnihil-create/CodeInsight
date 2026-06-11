#include<stdio.h>
#include<cmath>

int main(){
    int a,b,deg;
    scanf("%d %d %d",&a,&b,&deg);

    double PI = acos(-1);
    double rad = deg * PI / 180;

    double S = a * b * sin(rad) * 0.5;
    double c = sqrt(a*a + b*b - 2*a*b*cos(rad));
    double h = b *sin(rad);
    printf("%lf\n%lf\n%lf\n",S,a+b+c,h);
}
