#include<stdio.h>

int main()
{
    int i,j,a[30],n,temp=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=1;i<n-1;i++)
    {
        if(a[i-1]<a[i] && a[i]<a[i+1])
            temp++;

        else if(a[i-1]>a[i] && a[i]>a[i+1])
            temp++;
    }

    printf("%d",temp);

    return 0;
}
