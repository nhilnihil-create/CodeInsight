/*
    Author: Alam Khan
    AUST CSE 40th Batch

*/

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef deque<ll> dl;
typedef stack<ll> stl;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll,ll> mll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
#define sf(n)     scanf("%lld",&n)
#define sff(n,m)     scanf("%lld %lld",&n,&m)
#define sfff(n,m,r)     scanf("%lld %lld %lld",&n,&m,&r)
#define sfs(n)     scanf("%s",n)
#define pf(n)     printf("%lld\n",n)
#define pff(n,m)     printf("%lld %lld\n",n,m)
#define pfff(n,m,r)     printf("%lld %lld %lld\n",n,m,r)
#define pfs(n)     printf("%s\n",n)
#define pfcs(i,n)     printf("Case %lld: %lld\n",i,n)
#define pb     push_back
#define prf     printf
#define inf     2e11
#define low     -1000000000000
#define PI        acos(-1.0)
#define rep1(i,n) for(i=1;i<n;i++)
#define rep0(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define repe1(i,n) for(i=1;i<=n;i++)
#define repe0(i,n) for(i=0;i<=n;i++)
#define repe(i,a,n) for(i=a;i<=n;i++)
#define endl  "\n"
#define FAST  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr freopen("input.txt","r",stdin)
#define fw freopen("output.txt","w",stdout)

ll dp[1009][5009];
ll key[1009];
ll cost[1009];
ll n,m;
ll sol(ll keyno,ll mask)
{
    if(dp[keyno][mask]!=-1)
    {
        return dp[keyno][mask];
    }
    if(keyno==m)
    {
        if(mask==(1<<n)-1)
            return dp[keyno][mask] =0;
        return dp[keyno][mask] =inf;
    }
    ll res = inf;

    res = min(res,cost[keyno]+sol(keyno+1,mask | key[keyno]));
    res = min(res,sol(keyno+1,mask));

    return dp[keyno][mask] = res;
}
int main()
{
    ll i,t,k,j,x=0,y=0;
    FAST
    cin>>n>>m;

    for(i=0;i<m;i++)
    {
        ll cnt;
        cin>>cost[i]>>cnt;
        k = 0;
        while(cnt--)
        {
            cin>>x;
            k  =k| (1<<(x-1));
        }
        key[i] = k;

    }
    memset(dp,-1,sizeof dp);
    x = sol(0,0);
    if(x>=inf)
        cout<<-1<<endl;
    else cout<<x<<endl;

    return 0;
}

