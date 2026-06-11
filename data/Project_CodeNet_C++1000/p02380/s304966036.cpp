#include <cstdio>
#include <cmath>

int main(){
    int a,b,C;
    scanf("%d %d %d",&a,&b,&C);
    double r=C*M_PI/180;  //????????¢????????????
    double S,L,h;
    S=a*b*sin(r)/2;
    L=sqrt(a*a+b*b-2*a*b*cos(r))+b+a;
    h=b*sin(r);
    printf("%.8f %.8f %.8f\n",S,L,h);
    return 0;
}