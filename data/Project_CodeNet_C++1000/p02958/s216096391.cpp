#include<stdio.h>
int main()
{
    int n,i,cnt=0,p;
    scanf("%d",&n);
    int a[n];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(i!=a[i])
            cnt++;
    }
    if(cnt==2 || cnt==0)
        printf("YES");
    else
        printf("NO");

    return 0;
}