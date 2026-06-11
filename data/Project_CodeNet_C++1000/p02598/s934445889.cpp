#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
#define mod 998244353
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
//#define f(i,n) for(int i=1;i<=n;i++)
#define fo(i,k,n) for(int i=k;k<=n?i<=n:i>=n;k<=n?i+=1:i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
int modexp(int x,int y) {
   int res = 1;
   x = x % mod;
   while (y > 0)
   {
       if (y & 1LL)
           res = (res*x) % mod;
       y = y>>1;
       x = (x*x) % mod;  
   }
   return res;}
int invmod(int a){

   return modexp(a,mod-2);}
vector<int> edge[maxn];
void ipgraph(int m) {
   fo(i,1,m)
   {
       int a,b;
       cin>>a>>b;
       edge[a].pb(b);
       edge[b].pb(a);
   } }
void dfs(int node,int p) {
   for(int u : edge[node])
   {
       if(u!=p)
           dfs(u,node);
   }}
//////////////////////////////////////////////////////////////////////////////////////////////////
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    fo(i,1,n) cin>>a[i];
    int l = 1,r = (int)1e9;
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2,temp = 0;
        fo(i,1,n) a[i]%mid==0 ? temp+=a[i]/mid-1 : temp+=a[i]/mid;
        if(temp<=k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    d(ans)
}
int32_t main()
{
   IOS;
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
   int t=1;
   //cin>>t;
   fo(i,1,t)
   {
       //cout<<"Case "<<i<<": ";
       solve();
   }
}
