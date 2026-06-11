#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using boost::multiprecision::cpp_int;
using namespace std;
#define ll long long int
#define F first
#define S second
//#define endl "\n"
//#define nl cout<<endl;
#define pb push_back
#define ull unsigned long long 
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
//#define mod 100000007
#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 
bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
    return false;
}
bool cmp(int n, pair<int, int> const& p)
{
    return (p.first < n);
}
//me
ll const mod = 1e9+7;//998244353;
ll const inf = 1e18;
ll const maxn = 2e5+1;

ll dis[maxn], vis[maxn];
vector<ll> nodes[maxn];

void dfs(ll x){
     ll parWgt = dis[x];

     vis[x]=1;
     for(auto ch : nodes[x]){
          if(vis[ch]==0){
               dis[ch]+=parWgt;
               dfs(ch);
          }
     }
}

void solve()
{    

     ll n,q; cin >> n >> q;
     f(i,1,n){
          ll u, v; cin >> u >> v;
          nodes[u].pb(v);
          nodes[v].pb(u);
     }

     f(i,0,q){
          ll p,x; cin >> p >> x;
          dis[p]+=x;
     }

     dfs(1);

     f(i,0,n)
          cout << dis[i+1] << " ";
     
}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
          
          ll t;
          /**/t=1;
          /*/cin>>t;/**/
          f(testcases,0,t){
               //cout << "Case #" <<testcases+1<<": ";
               solve();
          }
 
 
    return 0;
}