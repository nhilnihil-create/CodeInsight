#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main ()
{
    double t,n,sum;
    scanf ("%lf%lf",&t,&n);
    sum=0;
    while (t--)
    {
        double a,b;
        scanf ("%lf%lf",&a,&b);
        if(sqrt(a*a+b*b)<=n)
        {
            sum++;
        }
        else
            continue;
    }
    printf ("%.f\n",sum);
    return 0;
}
