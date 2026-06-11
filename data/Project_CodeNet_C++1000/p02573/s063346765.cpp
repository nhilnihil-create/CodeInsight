#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define FT() int t; scanf("%d",&t); while(t--)
#define pb push_back
#define nl printf("\n")
#define fi(i,start,end) for(int i=start; i < (int)end ; ++i)
#define ip(n)   scanf("%d",&n)
#define mz(a)   memset(a,0,sizeof(a))
#define inpArr(A,n) fi(i,0,n)   ip(A[i]);
#define print(a)  for(auto i : a)   cout<<i<<" "; nl;
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll max(ll a,ll b)   {return a>b?a:b;}
ll min(ll a,ll b)   {return a<b?a:b;}
const int N = 2e5+1;
vector<int> adj[N];
vector<int> vis(N);
void dfs(int root,int val)
{
    vis[root] = val;
    for(auto i : adj[root])
        if(!vis[i])
            dfs(i,val);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("D:/Sublime/Rough/input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    //std::cout << std::fixed;
    //std::cout << std::setprecision(6);
    Fastio;
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int val = 0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,++val);
    }
    int a[val+1];
    mz(a);
    int mx = 0;
    for(auto i : vis)
        a[i]++;
    for(int i=1;i<=val;i++)
        mx = max(mx,a[i]); 
    //print(a);
    cout<<mx;
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s";
    #endif
    
    return 0;
}