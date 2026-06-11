#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
#define int long long
const int maxn=5005;
int d[maxn],real[maxn],front[maxn];
signed main()
{
    int k,q;
    scanf("%lld%lld",&k,&q);
    for(int i=1;i<=k;i++)
        scanf("%lld",&d[i]);
    while(q--)
    {
        int n,s,mod;
        scanf("%lld%lld%lld",&n,&s,&mod);
        memset(real,0,sizeof(real));
        for(int i=1;i<=k;i++)
            real[i]=d[i]%mod;
        int rounds=(n-1)/k,left=(n-1)%k;
        s%=mod;
        int check=0;
        for(int i=1;i<=k;i++)
            check+=real[i];
        check=rounds*check;
        for(int i=1;i<=left;i++)
            check+=real[i];
        check+=s;
        int ans=(n-1)-check/mod;
        int cnt=0;
        for(int i=1;i<=k;i++)
            if(real[i]==0)
                cnt++;
        ans=ans-rounds*cnt;
        for(int i=1;i<=left;i++)
            if(real[i]==0)
                ans--;
        printf("%lld\n",ans);
    }
    return 0;
}
