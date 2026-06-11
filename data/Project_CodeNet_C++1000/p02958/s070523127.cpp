#include<stdio.h>
#define size 55
int main()
{
    int i,j,n,a[size],cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=i+1)cnt++;
    }
    if(cnt<=2)printf("YES");
    else printf("NO");
}
