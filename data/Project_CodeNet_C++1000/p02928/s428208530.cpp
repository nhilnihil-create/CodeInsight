#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 500000000
#define IOS ios_base::sync_with_stdio(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prll(a,sz)  cout<<a[0];for(ll i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<ll,ll>pi;
typedef pair<ll,ll>pll;
//ll fx[]={0,0,1,-1};
//ll fy[]={1,-1,0,0};
//ll gx[]={0,0,1,1,1,-1,-1,-1};
//ll gy[]={1,-1,0,1,-1,0,1,-1};
bool check(ll n,ll p){return (1<<p)&n;}
const ll N=2010;
ll mod=1e9+7;
ll ara[N],A[N],D[N];
int  main()
{
    IOS;
    ll n,k;cin>>n>>k;
//    for(int i=0;i<n;i++)
//        ara[i]=2000-i;
    for(ll i=0;i<n;i++)cin>>ara[i];
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
            if(ara[j]<ara[i])A[i]++;
        for(ll j=i-1;j>=0;j--)
            if(ara[j]<ara[i])D[i]++;
        D[i]+=A[i];
    }
    ll res=0;
    for(ll i=0;i<n;i++)
    {
        ll temp=k*(k-1)/2;
        ll sum=((k*A[i])%mod+(temp%mod)*D[i])%mod;
//        cout<<"sum for "<<i<<" "<<D[i]<<"  "<<sum<<endl;
        res=(res+sum)%mod;
    }
    cout<<res<<endl;
}
/*
5 3
4 5 3 1 2

*/
