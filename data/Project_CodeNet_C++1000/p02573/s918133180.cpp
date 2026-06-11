//Tonight's the night and it is going to happen again and again.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define T ll t; cin>>t; while(t--)
#define mod 1000000007
#define inf 1000000000000000000
#define mem(name,val) memset(name,val,sizeof(name))
#define f(n) for(ll i=0;i<n;i++)
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define endl "\n"
ll gcd(ll a,ll b){if(b==0){return a;}return gcd(b,a%b);}
int c=0;
void dfs(int s,vector<int>adj[],int vis[])
{
  vis[s]=1;
  for(auto x:adj[s])
  {
    if(vis[x]==0)
    {
      c++;
      dfs(x,adj,vis);
    }
  }
}
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif
   int n,m,a,b,max1=0;cin>>n>>m;int vis[n+1];mem(vis,0);vector<int>adj[n+1];
   f(m)
   {
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   for(int i=1;i<=n;i++)
   {
    c=1;
    if(vis[i]==0)
    {
      dfs(i,adj,vis);
      max1=max(max1,c);
      
    }
   }
   cout<<max1; 
}
