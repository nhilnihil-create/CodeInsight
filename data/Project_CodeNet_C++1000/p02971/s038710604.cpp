#include <stdio.h>

int max(int a,int b){return a>b?a:b;}

int n;
int a[200050];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

    int left[200050];
    int right[200050];
    
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1],a[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],a[i+1]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\n",max(left[i],right[i]));
    }
}