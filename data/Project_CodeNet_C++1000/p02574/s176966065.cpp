#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;


#define pf                  printf
#define sf(a)               scanf("%d",&a)
#define sfl(a)              scanf("%lld",&a)
#define sff(a,b)            scanf("%d %d",&a,&b)
#define sffl(a,b)           scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)         scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)        scanf("%lld %lld %lld",&a,&b,&c)
#define sffff(a,b,c,d)      scanf("%d %d %d %d",&a,&b,&c,&d)
#define sffffl(a,b,c,d)     scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define sfffff(a,b,c,d,e)   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e)
#define sfffffl(a,b,c,d,e)  scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e)
#define sfc(a)              scanf("%c",&a)
#define pii                 pair<int,int>
#define ms(a,b)             memset(a,b,sizeof(a))
#define pb(a)               push_back(a)
#define pbp(a,b)            push_back({a,b})
#define db                  double
#define ft                  float
#define ll                  long long
#define ull                 unsigned long long
#define pii                 pair<int,int>
#define ff                  first
#define ss                  second
#define sz(x)               x.size()
#define all(x)              x.begin(),x.end()
#define CIN                 ios_base::sync_with_stdio(0); cin.tie(0)
#define max3(a, b, c)       max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c)       min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define for0(i,n)           for(int i=0;i<n;i++)
#define for1(i,n)           for(int i=1;i<=n;i++)
#define forrev(i,n)         for(int i=n-1; i>=0; i--)
#define forab(i,a,b)        for(int i=a;i<=b;i++)
#define forba(i,b,a)        for(int i=b;i>=a;i--)
#define stlloop(x)          for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define gcd(a, b)           __gcd(a, b)
#define lcm(a, b)           ((a)*((b)/gcd(a,b)))
#define case1(z)            cout<<"Case "<<z<<": "
#define case2(z)            printf("Case %d: ",z)
#define PI                  acos(-1) //3.14159265358979323846264338328
#define valid(tx,ty)        tx>=0 && tx<row && ty>=0 && ty<col
#define intlim              2147483648
#define N                   20000007
#define inf                 100000008
#define mod                 1000000007

map<ll,ll>m;
ll gk;


ll a[N],spf[N];
void sieve()
{
    ll i,j;
    for(i=2;i<N;i++)spf[i]=i;
    for(i=4;i<N;i+=2)spf[i]=2;
    for(i=3;i*i<N;i++)
    {
        if(spf[i]==i)
        {
            for(j=i*i;j<N;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void ola(ll x)
{
    set<ll>s;
    while(x!=1)
    {
        s.insert(spf[x]);
        x/=spf[x];
    }
    for(auto it : s)
    {
        if(m[it]==1)gk = 1;
        m[it] = 1;
    }
}



int main()
{
    sieve();
    ll n,i,g;
    cin>>n;
    for1(i,n)
    {
        cin>>a[i];
        ola(a[i]);
        if(i==1)
            g=a[i];
        else
            g = gcd(a[i],g);
    }
    if(gk==0)cout<<"pairwise coprime"<<endl;
    else if(g==1)cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
    return 0;
}



















