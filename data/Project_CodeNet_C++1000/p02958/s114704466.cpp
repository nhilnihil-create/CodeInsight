#include<stdio.h>

int main()
{
    int i,j,a[60],b[60],n,flag;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0,j=1;i<n;i++,j++)
    {
        b[i] = j;
    }

    for(i=0,flag=0;i<n;i++)
    {
        if(a[i]!=b[i])
            flag++;
    }

    if(flag<=2)
        printf("YES");
    else
        printf("NO");

    return 0;
}