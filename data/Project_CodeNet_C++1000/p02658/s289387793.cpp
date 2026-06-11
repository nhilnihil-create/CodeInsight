#include<stdio.h>

#define limit 1000000000000000000

int main()
{
    long long int a[100000],i,n,pro;

    scanf("%lld",&n);

    for(i=0,pro=1;i<n;i++)
    {
        scanf("%lld",&a[i]);

        if(a[i]==0)
        {
            printf("0");
            return 0;
        }
    }

    for(i=0;i<n;i++)
    {
        if(pro>limit/a[i])
        {
            printf("-1");
            return 0;
        }

        else
            pro = pro * a[i];

    }


    printf("%lld",pro);
    return 0;
}
