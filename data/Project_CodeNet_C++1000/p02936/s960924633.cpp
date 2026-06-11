#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372036854775807ll;
int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> increase;
void dfs(int node,int sum)
 {
  vis[node] = 1;
  increase[node] += sum;
  sum = increase[node];
  for(auto x : adj[node])
     if(!vis[x])
       dfs(x,sum);
 }
void solve()
  {
   int q;
   cin>>n>>q;
   adj = vector<vector<int>> (n+1);
   vis = vector<bool> (n+1,false);
   increase = vector<int> (n+1,0ll);
   loop(i,0,n-1)
    {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
   loop(i,0,q)
    {
      int p,x;
      cin>>p>>x;
      increase[p] += x;
    }
   dfs(1ll,0ll);
   loop(i,1,n+1)
    cout<<increase[i]<<" ";

  } 
signed main()
 {
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 