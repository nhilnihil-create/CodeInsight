#include<stdio.h>
int main()
{
    int i,n;
    long int h;
    scanf("%ld",&h);
    scanf("%d",&n);
    int a[n],s=0;
    for(i=0;i<n;i++)
    {
     scanf("%d",&a[i]);
     s=s+a[i];
    }
    if(h>s)
        printf("No");
    else
       printf("Yes");
    return 0;
}