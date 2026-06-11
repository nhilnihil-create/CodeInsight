/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 1e5+5 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG
vector<int> al[MAXN] ;
int h[MAXN] ;
bool visited[MAXN] ;
int ans=0 ;
void dfs(int node,int parent)
{
    if(visited[node]) return ;
    visited[node] = true ;
    bool good = true ;
    for(auto x:al[node])
    {
        if(h[x]>=h[node]) good = false ;
        dfs(x,node) ;
    }
    ans+=good ;
}

int main()
{
    fio ;
    /* ======================Start of code ================ */
    int n,m;cin>>n>>m ;
    f(i,0,n) cin>>h[i] ;
    f(i,0,m)
    {
        int a,b;cin>>a>>b;a--;b--;
        al[a].pb(b) ;
        al[b].pb(a) ;
    }
    // dfs(0,-1) ;
    f(i,0,n) dfs(i,-1) ;
    cout<<ans<<"\n" ;
    /* ======================End of code ================== */
}