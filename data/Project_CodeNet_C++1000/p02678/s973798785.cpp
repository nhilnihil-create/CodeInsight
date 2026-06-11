/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<(int)n;i++) 
const int MAXN = 1e5+5  ;
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
vector<int> par ;
void bfs(int root)
{
    queue<int> q ;
    q.push(root);
    while(!q.empty())
    {
        int node = q.front() ;
        q.pop() ;
        for(auto x:al[node])
        {
            if(par[x]!=-1) continue ;
            par[x] = node ;
            q.push(x) ;
        }
    }
}
int main()
{
    fio ;
    /* ======================Start of code ================ */
    int n,m;cin>>n>>m ;
    par.resize(n,-1) ;
    f(i,0,m)
    {
        int a,b;
        cin>>a>>b;a--;b--;
        al[a].pb(b) ;
        al[b].pb(a) ;
    }
    par[0] = 0 ;
    bfs(0) ;
    bool pos = true ;
    f(i,0,n) if(par[i]==-1) {pos=false;break ;}
    if(!pos) cout<<"No\n" ;
    else 
    {
        cout<<"Yes\n" ;
        f(i,1,n) cout<<(par[i]+1)<<"\n" ;
    }
    /* ======================End of code ================== */
}