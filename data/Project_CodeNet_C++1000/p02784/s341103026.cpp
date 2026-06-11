#include<stdio.h>
int main()
{
    long long int h,n,i,j,sum=0;
    scanf("%lld%lld",&h,&n);
    int a[n+10];
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    (sum-h)>=0?printf("Yes"):printf("No");
}
