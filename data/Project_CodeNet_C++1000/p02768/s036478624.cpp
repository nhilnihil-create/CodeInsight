#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=200010;
ll fact[N+5];
int m=1e9+7;
void pre_calc()
{
    fact[0]=1;
    for(int i=1;i<=N;i++)
        fact[i]=(fact[i-1]*i)%m;
}
ll power(ll a,ll b)     ///calculate a^b%m
{
    ll res=1;
    ll y=a;
    while(b>0)
    {
        if(b%2==1)
            res=(res*y)%m;
        y=(y*y)%m;
        b/=2;
    }
    return res;
}
///(1/a)%m=a^(m-2)%m

ll mmi(ll n)
{
    return power(n,m-2);
}

ll ncr(ll n,ll r)
{
    r=max(r,n-r);
    ll res=1;
    for(ll i=r+1;i<=n;i++)
        res=(res*i)%m;
//    cout<<"res = "<<res<<endl;
    res=(res*mmi(fact[n-r]));
    return res;
}
int main()
{
    IOS;
    pre_calc();

//    cout<<ncr(100000000,2)<<endl;
    ll n,a,b;cin>>n>>a>>b;

    ll res=(power(2,n)-ncr(n,a)-ncr(n,b)-1)%m;
    if(res<0)res+=m;
    cout<<res<<endl;
}
