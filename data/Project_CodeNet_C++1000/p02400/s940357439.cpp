# include <stdio.h>
int main()
{
    double a,b,c,d;
    scanf("%lf",&a);
    b=3.1415926535897932384626433*a*a;
    c=2*3.1415926535897932384626433*a;
    printf("%.6lf %.6lf\n",b,c);
    return 0;
}
