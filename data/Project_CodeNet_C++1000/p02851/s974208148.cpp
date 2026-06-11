#pragma GCC optimize(2)
#include <bits/stdc++.h>
typedef long long ll;
const int mod=1e9+7;
const int maxn=2e6+16;
const ll INF=100000000000005;
const double eps=1e-11;
using namespace std;
ll n,m,p;
map<ll,ll>mp;
ll sum[maxn];
ll num[maxn];
int main()
{
    ll res=0;//记录最终答案
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&num[i]);
        sum[i]=sum[i-1]+num[i];
    }
    for(int i=1;i<=n;i++)
        sum[i]=(sum[i]-i%m+m)%m;//预处理前缀和
    ll low=min(m-1,n);
    for(int i=0;i<=low;i++)
    {
        res+=mp[sum[i]];
        mp[sum[i]]++;
    }
    for(int i=low+1;i<=n;i++)
    {
        mp[sum[i-m]]--;
        res+=mp[sum[i]];
        mp[sum[i]]++;
    }
    printf("%lld\n",res);
    return 0;
}
 
 
 