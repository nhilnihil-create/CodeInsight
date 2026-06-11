#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define pii pair<int,int>
#define pb(x) push_back(x)
#define lbound lower_bound
#define ubound upper_bound
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcountll(x)
#define heap_min priority_queue<int,vector<int>,greater<int>>
#define heap_max priority_queue<int>
#define precision(x) cout << setprecision(x) << fixed;
#define printv(v) for(auto p : v) cout << p << " ";
#define printa(a,n) for(int i = 0 ; i < n ; i++) cout << a[i] <<" "; 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int vis[100001];
vector<vector<int>>adj;

void dfs(int node){
  vis[node] = 1;
  for(auto p : adj[node]){
    if(vis[p] == 0){
      dfs(p);
    }
  }
}
int32_t main()
{
   fast;
   #ifndef ONLINE_JUDGE
   freopen("goodluckin.txt","r",stdin);
   freopen("goodluckout.txt","w",stdout);
   #endif

   int cnt = 0;
   int n,m;
   cin >> n >> m;
   adj.resize(n+1);
   int x,y;
   for(int i = 0 ; i < m ; i++){
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
   }
   for(int i = 1 ; i<=n ; i++){
    if(vis[i] == 0){
      dfs(i);
      cnt++;
    }
   }

   int ans = cnt-1;
   for(int i = 1; i <=n ; i++){
    if(vis[i] == 0){
        ans++;
      }
   }
   cout << ans;

}
