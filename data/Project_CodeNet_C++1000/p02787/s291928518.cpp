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
int dp[1040][10004];
int Hp[1040],mp[1003];
int n;
int call(int idx,int hp)
{
    if(hp<=0)return 0;
    if(idx==n)return inf;
    if(dp[idx][hp]!=-1)return dp[idx][hp];
    int f1=mp[idx]+call(idx,hp-Hp[idx]);
    int f2=call(idx+1,hp);
    return dp[idx][hp]=min(f1,f2);
}
int main()
{
    IOS;
    meM(dp,-1);
    int h;
    cin>>h>>n;
    for(int i=0;i<n;i++)
        cin>>Hp[i]>>mp[i];
    cout<<call(0,h)<<endl;
}






