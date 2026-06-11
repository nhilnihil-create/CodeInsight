/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 2e5+5 ;
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
int a[MAXN] ;
int dist[MAXN] ;
bool visited[MAXN] ;
int loopPoint ;
vector<int> steps ;
void dfs(int node,int parent)
{
    if(visited[node]) 
    {
        loopPoint = dist[node] ;
        return ;
    }
    visited[node] = true ;
    steps.pb(node) ;
    dist[node] = dist[parent]+1 ;
    dfs(a[node],node) ;
}
int main()
{
    fio ;
    /* ======================Start of code ================ */
    ll n,k;cin>>n>>k ;
    f(i,1,n+1) cin>>a[i] ;
    dist[0] = -1 ;
    dfs(1,0); 
    int basePos = loopPoint ;
    if(k<=basePos) return cout<<steps[k]<<"\n",0 ;
    k-=basePos ;
    int loopSize = steps.size()-basePos ;

    cout<<steps[(int)(k%loopSize)+basePos]<<"\n" ;
    /* ======================End of code ================== */
}