#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 42;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > ppi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(s) for(int i=0;i<s.length();i++)
#define input int t; cin>>t; while(t--)
#define SORT(arr) sort(arr,arr+n);
#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
#define mod 998244353
#define MAXN 1000010
ll mE(ll x,ll y)
{
    ll result=1;
    while(y)
    {
        if(y&1)
            result=((result%MOD)*(x%MOD))%MOD;
        x=((x%MOD)*(x%MOD))%MOD;
        y>>=1;
    }
    return result%MOD;
}
int noOfDigits(ll k)
{
    int cnt=0;
    while(k)
    {
        cnt++;
        k/=10;
    }
    return cnt;
}
class DisJointSet
{
    public:
              vector<int> par;
              vector<int> size;
              int total_size;
              void init(int n)
              {
                  par.resize(n);
                  size.resize(n);
                  for(int i=0;i<n;i++) 
                     par[i]=i;
                  for(int i=0;i<n;i++)
                     size[i]=1;
                  total_size=n;
              }
              int get_superParent(int x)
              {
                  if(x==par[x])
                      return x;
                  else
                      return par[x]=get_superParent(par[x]); //Path Compression
              }
              void unite(int x,int y)
              {
                  int superParentX=get_superParent(x);
                  int superParentY=get_superParent(y);
                  if(superParentX!=superParentY)
                  {
                      par[superParentX]=superParentY;
                      size[superParentY]+=size[superParentX];
                      size[superParentX]=0;
                      total_size--;//When two different components get connected, then their total size reduces by 1 as they become common and their unique identity is vanished..
                  }
              }
};
vector<int> graph[100005];
vector<bool> visited(100005,false);
void dfs(int src)
{
    visited[src]=true;
    for(int it:graph[src])
    {
        if(!visited[it])
           dfs(it);
    }
    return;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            ans++;
        }
    }
    ans--;
    cout<<ans<<endl;
    return;
}   
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //input{
        //cout << "Case #" << t  << ": ";
        solve();
    //}
    return 0;
}