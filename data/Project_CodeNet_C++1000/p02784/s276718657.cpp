#include<stdio.h>
int main()
{
    long long int i,j=0,h,n,s=0;
    scanf("%lld%lld", &h,&n);
    long long int a[n+5];
    for(i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        s=s+a[i];
        if(s>=h)
        {
            j=1;
            break;
        }
    }
    if(j==1)
        printf("Yes\n");
    else
        printf("No\n");
}
