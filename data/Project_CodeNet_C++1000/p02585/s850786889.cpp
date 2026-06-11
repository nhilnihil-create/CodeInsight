#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(a) ((a) & -(a))
#define clean(a, b) memset(a, b, sizeof(a))
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 9;
// typedef pair<int,int>P;

int _;

//========================================================================
ll Pp[maxn],Cc[maxn],mp[5009];
ll a[maxn],sum[maxn];
vector<ll>ve[5009];
//========================================================================
int main()
{
    ll n,k;
    ll x;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        Pp[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        Cc[i]=x;
    }
    ll ans=-1e18;
    for(ll i=1;i<=n;i++)
    {
        ll now=i;
        clean(mp,0);
        while(1)
        { 
            now=Pp[now];
            // printf("mp[%lld]=%lld\n",now,mp[now]);
            if(mp[now]==1) break;
            mp[now]=1;
            sum[i]+=Cc[now];
            ve[i].push_back(Cc[now]);
        }
        int len=ve[i].size();
        ll d=k/len;
        ll m=k%len;
        // printf("%lld %lld %lld\n",d,m,len);
        now=0;
        if(sum[i]>0) 
        {
            if(m==0) 
            {
                now=(d-1)*sum[i];
                m=len;
            }
            else now=d*sum[i];
            for(int j=0;j<m;j++) now+=ve[i][j],ans=max(ans,now);
        }
        else 
        {
            if(d==0)             
            {
                for(int j=0;j<m;j++) now+=ve[i][j],ans=max(ans,now);
            }
            else 
            {
                for(int j=0;j<len;j++) now+=ve[i][j],ans=max(ans,now);
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     int len=ve[i].size();
    //     for(int j=0;j<len;j++) printf("%lld ",ve[i][j]);
    //     printf("\n");
    // }
    printf("%lld\n",ans);
    return 0;
}
