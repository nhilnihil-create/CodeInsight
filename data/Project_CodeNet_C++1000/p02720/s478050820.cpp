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
const int N=100010;
bool lun(ll num)
{
    int prev=num%10;
    num/=10;
    while(num>0)
    {
        int d=num%10;
        num/=10;
        if(abs(d-prev)>1)return 0;
        prev=d;
    }
    return 1;
}
ll nxt_lun(ll x)
{
    vector<int>v;
    if(lun(x))return x;
    ll num=x;
    ll prev=num%10;
    ll mul=1;
    num/=10;
    v.pb(prev);
    while(num>0)
    {
        int d=num%10;
        num/=10;
//        cout<<d<<" "<<prev<<endl;
        if(d-prev>1){
            v[v.size()-1]=d-1;
            for(int i=v.size()-2;i>=0;i--)
                v[i]=max(v[i+1]-1,0);
        }
        else if(prev-d>1)
        {
            d=d+1;
            v[v.size()-1]=d-1;
            for(int i=v.size()-2;i>=0;i--)
                v[i]=max(v[i+1]-1,0);
        }
        v.pb(d);
        prev=d;
    }
    ll z=0;
    for(int i=v.size()-1;i>=0;i--)
        z=z*10+v[i];
    return z;
}
ll ara[N];
int main()
{
    IOS;
    int cnt=0;
    ara[0]=0;
    for(int i=1;i<=100000;i++)
    {
        ara[i]=nxt_lun(ara[i-1]+1);
//        cout<<ara[i]<<endl;
    }
    int n;cin>>n;
    cout<<ara[n]<<endl;
}






