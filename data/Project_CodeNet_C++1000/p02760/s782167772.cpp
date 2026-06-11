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
#define inf 20000000000000000
#define mod 998244353
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
#define ma 200
ll a[4][4];
ll mark[ma];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,x,y,n;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)cin>>a[i][j];
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        mark[x]=1;
    }
    x=a[0][0],y=a[1][1];
    ll x1=a[2][2];
    bool f=0;
    if(mark[x]==mark[x1]==mark[y]&&mark[x]==1)
    {
        f=1;
    }
    x=a[0][2],y=a[1][1],x1=a[2][0];
    if(mark[x]+mark[y]+mark[x1]==3)
    {
        f=1;
    }

    else
    {
        for(i=0;i<3;i++)
        {
            ll cn=0,cn1=0;
            for(j=0;j<3;j++)
            {
                cn+=mark[a[i][j]];
                cn1+=mark[a[j][i]];
            }
            if(cn==3||cn1==3)f=1;
        }

    }
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
