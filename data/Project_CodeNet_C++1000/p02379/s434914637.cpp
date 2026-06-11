#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    double x, X, y, Y, a, b, l;
    scanf("%lf %lf %lf %lf", &x, &y, &X, &Y);
    a = fabs(X - x);
    b = fabs(Y - y);
    l = sqrt(a * a + b * b); 
    printf("%f", l);
}
