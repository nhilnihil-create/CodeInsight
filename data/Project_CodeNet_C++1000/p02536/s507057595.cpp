/* ****mittal21**** */
#include<bits/stdc++.h>
#define ll          long long int 
#define ld          long double
#define pb          push_back
#define endl        '\n'
#define pii         pair<long long int,long long int>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll )x.size()
#define hell        1000000007
#define jell        998244353
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define repr(i,a,b)   for(ll int i=a;i>=b;i--)
#define lbnd    lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define DEC(N)  cout << std::fixed; cout << setprecision(N);
using namespace std;
#define N  100005
std::vector<ll> a[N];
ll vis[N];
void dfs(ll node)
{
  vis[node]=1;
  for(auto i:a[node])
  if(!vis[i])
  dfs(i);
}
void solve()
{
   ll n,m;
   cin>>n>>m;
   ll cnt=0;
   for(int i=0;i<m;i++)
   {
    ll x,y;
    cin>>x>>y;
    a[x].pb(y);
    a[y].pb(x);
   }
   for(int i=1;i<=n;i++)
   {
     if(!vis[i])
     {
        dfs(i);
        cnt++;
     }
   }
   cout<<cnt-1;
   return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll testcase=1;
    //cin>>testcase;
    while(testcase--)
    {
        solve();
    }
    return 0;
}