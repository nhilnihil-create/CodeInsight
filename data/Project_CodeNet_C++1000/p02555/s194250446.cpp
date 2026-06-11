#include<cstdio>
#define mod 1000000007
#define ll long long
using namespace std;
ll d[2001],n;
int main()
{
    scanf("%lld",&n);
    d[0]=1;
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=i-3;j++)
		{
            d[i]+=d[j];
            d[i]%=mod;
        }
    printf("%d",d[n]);
    return 0;
}