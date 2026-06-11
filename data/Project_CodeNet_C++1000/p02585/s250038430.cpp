/**
 *    author:  Daredevil666
 *    institution: IIT Patna
**/
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define ll long long int
#define REP(i,a,n) for(i=a;i<=n;i++)
#define F(i,a,b) for(i=a;i<b;i++)
#define RF(i,b,a) for(i=b;i>=a;i--)
#define IOS  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const ll mod=1e15;
const ll MAXN=5200;
ll i,j,sizes=0;
vector<ll> v[MAXN],vis(MAXN),p(MAXN),c(MAXN);
void dfs(ll k)
{
    vis[k]=1;
    v[sizes].push_back(c[k]);
    if(vis[p[k]]==0)
    {
        dfs(p[k]);
    }
}
int main()
{
IOS
/*#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE*/
ll n,k;
cin>>n>>k;
F(i,0,n)
{
    cin>>p[i];
    p[i]--;
}
F(i,0,n)
{
    cin>>c[i];
}
F(i,0,n)
{
    if(vis[i]==0)
    {
        dfs(i);
        sizes++;
    }
}
ll a[sizes+2][n+2];
ll ans=-mod;
F(i,0,sizes)
{
    ll sum=0,g=v[i].size();
    F(j,0,v[i].size())
    {
       sum+=v[i][j];
       a[i][j+1]=-mod;
    }
    F(j,0,v[i].size())
    {
        ll s=0;
       for(ll t=j;t<j+g;t++)
       {
           //cout<<v[i][t%g]<<" ";
           s+=v[i][t%g];
           a[i][t-j+1]=max(a[i][t-j+1],s);
       }

    }
    ll s=0,l=k;
    if(sum>0)
    {
      ll u=ceil((double)k/g);
      if(u!=0)
      {s+=sum*(u-1);
      l-=(u-1)*g;
      }
    }
    ll p=-mod;
    REP(j,1,min(g,l))
    {
        //cout<<a[i][j]<<" ";
        p=max(p,a[i][j]);
    }
    //nl
    s+=p;
    ans=max(s,ans);
}
cout<<ans;
return 0;
}
