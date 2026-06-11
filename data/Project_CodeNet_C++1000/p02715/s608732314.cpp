#include<bits/stdc++.h>
using namespace std;
long long m=1e9+7;

long long power(long long x, long long y, long long p)
{
    long long res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1) res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    long long n,k;
    cin>>n>>k;
    long long count[k+1]={0};
    for(long long i=1; i<=k; i++)
    {
        long long x=k/i;
        count[i]=power(x,n,m);
    }
    long long ans=0;
    for(long long i=k; i>=1; i--)
    {
        if(count[i]==0) continue;
        for(long long j=2; i*j<=k; j++)
            count[i]=(count[i]-count[i*j]+m)%m;
        ans=(ans+(count[i]*i)%m)%m;
    }
    cout<<ans<<endl;
    return 0;
}
