#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int deg[200009]={0};

int main()
{
    long long n,k,i,r,sum,s;
    scanf("%lld%lld",&n,&k);
    for(i=1;i<=n-1;i++){
        long long v1,v2;
        scanf("%lld%lld",&v1,&v2);
        deg[v1]++;
        deg[v2]++;

    }

    sum=k;
    for(s=k-1,i=1;i<=deg[1];i++,s--)
        sum=sum*s%mod;
    for(i=2;i<=n;i++){

        for(int j=1,s=k-2;j<deg[i];j++,s--)
            sum=sum*s%mod;
    }
    if(sum<=0)
        sum=0;
    printf("%lld\n",sum);

    return 0;
}
