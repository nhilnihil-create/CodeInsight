#include<iostream>
#include<stdio.h>
using namespace std;
#define maxn 200005
int main ()
{
    int n,r=0,w=0,r1=0,w1=0,r2,w2,sum;
    char c[maxn];
    scanf ("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf ("%c",&c[i]);
        if(c[i]=='R')
            r++;
        else if(c[i]=='W')
            w++;
    }
    for(int i=0;i<=r;i++)
    {
        if(c[i]=='W')
        w1++;
    }
        r1=r-w1;
        r2=r-r1;
        sum=min(r,w);
        sum=min(r2,sum);
        printf("%d\n",sum);
    return 0;
}