#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define mp make_pair
#define pb push_back
#define f first
#define s second
const ll mod=998244353;
const ll N=2e5+5;
unordered_map<ll,vector<ll>> adj;
vector<ll> vis(300005,0);
vector<ll> p(100005,0);
ll c[100005];
ll cnt;
ll n;
void dfs(ll node)
{
  if(vis[node])
    return;
  vis[node]=1;
  cnt++;
  for(auto i:adj[node])
    {
      dfs(i);
    }
}
struct range{
  ll l;
  ll r;
  ll index;
};
bool cmp(range& p1,range& p2)
{
     return p1.l<p2.l;
}
int main()
{
   ll i,n;
   cin>>n;
   ll temp=n-1;
   ll cnt=0;
   for(i=1;i<=n-1;i++)
   {
        cnt+=temp/i;
   }
   cout<<cnt;
}