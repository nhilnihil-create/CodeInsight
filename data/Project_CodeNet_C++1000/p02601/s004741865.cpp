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
#define ma 1000005

ll get(ll x)
{
    if(x<600)return 8;
    if(x<800)return 7;
    if(x<1000)return 6;
    if(x<1200)return 5;
    if(x<1400)return 4;
    if(x<1600)return 3;
    if(x<1800)return 2;
    if(x<2000)return 1;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k,i,j,x,y,z;
    while(cin>>x>>y>>z)
    {
        cin>>k;
        for(i=1;i<=k;i++)
        {
            if(y<=x)y*=2;
            else if(z<=y)z*=2;
           // cout<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
        }
        //cout<<x<<" "<<y<<" "<<z<<endl;
        if(y>x&&z>y)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
