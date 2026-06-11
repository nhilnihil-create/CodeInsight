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
const int N=1000100;
vector<ll>v;
ll a[N],b[N],c[N];
int main()
{
    IOS;
    int x,y;
    cin>>x>>y;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    for(int i=0;i<k;i++)cin>>c[i];
    sort(a,a+n);
    sort(b,b+m);
    sort(c,c+k);
    for(int i=n-1;i>=n-x;i--)v.pb(a[i]);
    for(int i=m-1;i>=m-y;i--)v.pb(b[i]);
    for(int i=k-1;i>=max(k-x-y,0);i--)
        v.pb(c[i]);
    sort(alL(v));
    ll res=0;
    for(int i=v.size()-1;i>=v.size()-x-y;i--)
        res+=v[i];
    cout<<res<<endl;
}






