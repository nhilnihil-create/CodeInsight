#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int a[1001];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
            return 0;
            int p=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            p=p+a[i];
        }
        double m=p*1.0/n;
        double t=0;
        for(int i=1;i<=n;i++)
        {
            t=t+(a[i]-m)*(a[i]-m)/n;
        }
        double t2=sqrt(t);
        printf("%.8lf\n",t2);
    }
}