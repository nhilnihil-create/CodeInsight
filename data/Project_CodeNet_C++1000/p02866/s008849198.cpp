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
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
bool check(int n,int p){return (1<<p)&n;}
const int N=100010;
int ara[N];
ll m=998244353;
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
//        cout<<"res = "<<res<<endl;
    }
    return res;
}
int aa[N];
int main()
{
    IOS;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        aa[i]=a;
        ara[a]++;
    }
    ll res=1;
    if(ara[0]!=1||aa[0]!=0){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        res=(power(ara[i-1],ara[i])*res)%m;
    }
    cout<<res<<endl;
}






