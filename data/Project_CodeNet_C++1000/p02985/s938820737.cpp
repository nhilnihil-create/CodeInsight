///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;

inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


const int M=100005;
int n,k;
vector<int>adj[M];
int ses=1LL;
void dfs(int u,int par)
{
     int cnt=k-1;
     if(par)cnt--;
     for(auto v:adj[u])
     {
         if(v==par)continue;
         ses=gun(ses,cnt);
         cnt--;
     }
     for(auto v:adj[u])
     {
         if(v==par)continue;
         dfs(v,u);
     }
}
 main()

{
    fast
    cin>>n>>k;
    f(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ses=k;
    dfs(1,0);
    cout<<ses<<endl;
    return 0;

}



































