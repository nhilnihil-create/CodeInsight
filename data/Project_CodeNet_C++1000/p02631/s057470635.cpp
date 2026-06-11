#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define pf printf
#define sf scanf
#define ff first
#define ss second
#define clr clear()
#define sz size()
#define pb push_back
#define mk make_pair
#define pi acos(-1)
#define inf 2000000000000000000
#define mod 1000000007
#define ull unsigned long long int
#define f(i,k,n) for(i=k;i<n;i++)
#define fr(i,n,k) for(i=n;i>=k;i--)
#define ent(a) scanf("%lld",&a)
#define ent2(a,b) scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a) memset(a,0,sizeof(a))
#define vec(v,s) vector<ll>v[s]
#define arr(a,s) ll a[s];
/*#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
//knight and king//
int dr[]= {2,2,-2,-2,1,-1,1,-1};
int dc[]= {1,-1,1,-1,2,2,-2,-2};
int dr1[]= {0,0,1,1,1,-1,-1,-1};
int dc1[]= {1,-1,1,0,-1,0,1,-1};
int dr2[]= {0,0,1,-1};
int dc2[]= {1,-1,0,0};
////////////////////////////
using namespace std;
#define ma 2000005
ll fr[ma];

ll bigmod(ll n,ll p)
{
    if(p==0)return 1;
    ll x=bigmod(n,p/2);
    x=(x*x)%mod;
    if(p%2)x=(x*n)%mod;
    return x;
}

ll ncr(ll n,ll r)
{
    ll r1=(fr[n-r]*fr[r])%mod;
    r1=bigmod(r1,mod-2);
    return (fr[n]*r1)%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,i,j,u,v,k,x,m;
    fr[0]=1;
    for(i=1;i<ma;i++)fr[i]=(fr[i-1]*i)%mod;
    while(cin>>n)
    {
        ll xo=0;
       for(i=1;i<=n;i++)
       {
           cin>>fr[i];
           xo^=fr[i];
       }
       for(i=1;i<=n;i++)
       {
           cout<<(xo^fr[i])<<" ";
       }
       cout<<endl;
    }
    return 0;
}
