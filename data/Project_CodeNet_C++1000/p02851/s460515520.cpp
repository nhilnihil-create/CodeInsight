#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 200000+10;

int n,k;
int a[maxn],sum[maxn],b[maxn];
map<int,int> cnt;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%k;
    for (int i=1;i<=n;i++) b[i]=((sum[i]-i)%k+k)%k;
    //for (int i=0;i<=n;i++) printf("%d ",b[i]); printf("\n");
    cnt[0]++;
    LL ans=0; int pre=0;
    for (int i=1;i<=n;i++)
    {
        while (i-pre>=k)
        {
            cnt[b[pre]]--;
            pre++;
        }
        ans+=cnt[b[i]];
        cnt[b[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}
