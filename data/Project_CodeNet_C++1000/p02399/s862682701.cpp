#include <cstdio>

int main(){
    int a, b;
    double A,B;
    scanf("%d %d",&a, &b);
    A=a;
    B=b;
    printf("%d %d %.6lf\n",a/b, a%b, A/B);
    return 0;
}