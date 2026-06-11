///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

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
const int M=2003;

inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


int dp[M][M];
 main()

{
    fast
    int n,m;
    cin>>n>>m;
    int s[n+3],t[m+2];
    f(i,1,n)cin>>s[i];
    f(i,1,m)cin>>t[i];
    dp[0][0]=0;
    f(i,1,n)
    {
        f(j,1,m)
        {
           int x=0;
           x=ad(dp[i][j-1],dp[i-1][j]);
           x=sub(x,dp[i-1][j-1]);
           dp[i][j]=x;
           x=0;
           if(s[i]==t[j])
           {
               x=ad(dp[i-1][j-1],1);
           }
           dp[i][j]=ad(dp[i][j],x);
        }
    }
    dp[n][m]=ad(dp[n][m],1);
    cout<<dp[n][m]<<endl;
    return 0;

}



































