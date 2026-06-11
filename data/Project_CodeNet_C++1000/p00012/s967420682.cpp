#include <stdio.h>
double root(double a1, double b1, double a2, double b2, double a3, double b3) {double S=a1*b2+a2*b3+a3*b1-b1*a2-b2*a3-b3*a1;if (S<0) return -S; else return S;}
int main() {
    double x1,x2,x3,xp,y1,y2,y3,yp;while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&xp,&yp)!=EOF) {
    double s=root(x1,y1,x2,y2,x3,y3),s1=root(x1,y1,x2,y2,xp,yp),s2=root(x1,y1,xp,yp,x3,y3),s3=root(xp,yp,x2,y2,x3,y3);
    if (s==s1+s2+s3) puts("YES"); else puts("NO");} return 0;}