#include <bits/stdc++.h>
using namespace std;
#define ll  long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pop_back
#define in insert
#define ff first
#define ss second
#define e endl
#define MAXN 200005
#define debug cout<<"we are debuuging"<<endl;
#define MOD 1000000007
ll fast_expo(ll x,ll p)
{if(p==0) return 1;
else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
vector<int> g[MAXN];
vector<int> arr(MAXN);
vector<int> ans(MAXN);
void dfs(int u,int par,int val)
{
     ans[u]+=val;
     for(auto v : g[u])
     {
          if(v==par)
               continue;
          dfs(v,u,arr[v]+val);
     }
}
int main()
{
     int n,q;
     cin>>n>>q;
     int u,v;
     for(int i=0;i<n-1;i++)
     {
          cin>>u>>v;
          g[u].pb(v);
          g[v].pb(u);
     }
     int p,val;
     while(q--)
     {
          cin>>p>>val;
          arr[p]+=val;
     }
     dfs(1,-1,arr[1]);
     for(int i=1;i<=n;i++)
          cout<<ans[i]<<" ";
}
