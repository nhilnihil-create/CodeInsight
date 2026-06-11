#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    double f;
    f=(1.0*a)/(1.0*b);
    printf("%d %d %.8lf\n",a/b,a%b,f);
    return 0;
}