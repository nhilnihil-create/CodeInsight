#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,i;
    scanf("%d",&n);
    long long a[n],b[n],sum=0;
    for (i=0;i<n+1;i++)
    {
                scanf("%lld",&a[i]);
    }
    for (i=0;i<n;i++)
    {
                scanf("%lld",&b[i]);
    }
    for (i=0;i<n;i++)
    {
                 int mon = min(a[i],b[i]) ;
                 //printf("mon 1 %d\n",mon);
                 sum+= mon;
                 b[i]-= mon;
//printf("mon 2 %lld\n",mon);
                 mon = min(a[i+1],b[i]);
                 sum+= mon ;
                 //printf("mon 3 %lld\n\n",mon);
                 b[i]-=mon;
                 a[i+1]-= mon;
    }
    printf("%lld",sum);
    return 0;
}
