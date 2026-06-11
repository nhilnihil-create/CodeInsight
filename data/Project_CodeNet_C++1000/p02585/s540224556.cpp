#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define _h cout<<"here"<<endl;
#define fill(a,v) memset(a,v,sizeof(a));
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<n;i+=1)
#define prd(a,n) rep(i,n) cout<<a[i]<<" \n"[i==n-1];// printf("%s\n"," " );
#define ff first
#define ss second
#define pu push_back
const int inf = 1e9+10;
const ll INF = 2e18+10;
const int Mod = 1e9+7;
const int MAXN = 1000010;
const int N=5e3+10;
const int M=210;
const int M1=1e9+7;
const int M2=1e9+9;
const int base=131;
int p[N],c[N],vis[N];
vector<ll> val;
vector<int> G[N];
void dfs(int s,ll sum=0)
{
  vis[s]=1;
  for(auto v:G[s])
  {
    sum+=c[v];
    val.pu(sum);
    if(!vis[v])
    {
      // sum+=c[v];
      // val.pu(sum);
      dfs(v,sum);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n,k;
  ll ans=-INF;
  cin>>n>>k;
  for(int i=1;i<=n;i++) cin>>p[i];
  for(int i=1;i<=n;i++) cin>>c[i];
  for(int i=1;i<=n;i++)
  {
    int u=i;
    while(!vis[u])
    {
      vis[u]=1;
      int v=p[u];
      G[u].push_back(v);
      u=v;
    }
  }
  for(int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    val.clear();
    dfs(i);
    int sz=val.size();
    sz=min(sz,k);
    ll cyc_mx=-INF;
    for(int j=0;j<sz;j++)
    {
      // cout<<val[j]<<endl;
      ans=max(ans,val[j]);
      cyc_mx=max(cyc_mx,val[j]);
    }
    // cout<<cyc_mx<<endl;
    // cout<<ans<<endl;
    ll cycle=val.back();
    sz=val.size();
    if(k>sz)
    {
      int r=k%sz;
      ll q=k/sz;
      ll temp=-INF;
      for(int j=0;j<r;j++) temp=max(temp,val[j]);
      if(cycle<0)
      {
        // ll temp=-INF;
        // for(int j=0;j<r;j++) temp=max(temp,val[j]);
        temp+=cycle;
        // ans=max(ans,temp);
      }
      else if(cycle>=0)
      {
        temp+=cycle*q;
        temp=max(temp,cycle*(q-1)+cyc_mx);
      }
      ans=max(ans,temp);
    }
  }
  cout<<ans<<endl;
  return 0;
}
