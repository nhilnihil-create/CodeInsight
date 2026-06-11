#include<cstdio>
#include<algorithm>
const int N=300100;
using namespace std;
typedef long long ll;
ll n,x;
ll sum[N],c[N];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        c[x]++;
        sum[c[x]]++;
    }
    for(ll i=1;i<=n;i++)
        sum[i]+=sum[i-1];
    //for(ll i=1;i<=n;i++)
    //printf("%lld %lld\n",c[i],sum[i]);
    for(ll i=1;i<=n;i++)
    {
        ll l=1,r=n,ans=0,mid;
        while(l<=r)
        {
            mid=(r-l)/2+l;
            if(mid*i<=sum[mid])
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}