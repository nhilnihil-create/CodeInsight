#include<stdio.h>

int main()
{
    int i,h,a[100000],n,sum=0;

    scanf("%d %d",&h,&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

        sum = sum + a[i];
    }

    if((h-sum)<=0)
        printf("Yes");
    else
        printf("No");


    return 0;
}
