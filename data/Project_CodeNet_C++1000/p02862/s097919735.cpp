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
const int N=4000010;
ll fact[N];
ll m=1e9+7;
ll power(ll a,ll p)
{
    ll res=1;
    ll y=a;
    while(p>0)
    {
        if(p&1)res=(res*y)%m;
        p>>=1;
        y=(y*y)%m;
    }
    return res;
}
int main()
{
    IOS;
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=(fact[i-1]*i)%m;
    ll a,b;cin>>a>>b;
    ll x=-1,y=-1;
    if((2*b-a)%3==0)x=(2*b-a)/3;
    if((2*a-b)%3==0)y=(2*a-b)/3;
    if(x<0||y<0)cout<<0<<endl;
    else{
//        cout<<x<<" "<<y<<endl;
//        ll res=(fact[x+y])/(fact[x]*fact[y]);
        ll res=(((fact[x+y]*power(fact[x],m-2))%m)*(power(fact[y],m-2)))%m;
        cout<<res<<endl;
    }
}







