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
const int M=100009;

inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int dp[M+4][2],n;
string s;
int solve(int pos,int is_sml)
{
    if(pos>=n)
    {
        return 1;
    }
    int &ret=dp[pos][is_sml];
    if(ret!=(-1))return ret;
    ret=1;
    if(is_sml)
    {
        ret=gun(3LL,solve(pos+1,is_sml));
    }
    else
    {
         if(s[pos]=='0')
         {
             ret=solve(pos+1,is_sml);

         }
         else
         {
             int x=gun(2LL,solve(pos+1,is_sml));
             int y=solve(pos+1,1);
             ret=ad(x,y);
         }

    }
    return ret%mod;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>s;
    n=s.size();
    cout<<solve(0,0)<<endl;
    return 0;

}



































