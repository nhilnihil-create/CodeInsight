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

string s;
int dp[M+3][13],sz;
int ten[M+4];
int n;
int solve(int pos,int rem)
{
    rem=rem%13;
    if(pos==sz)
    {
         if(rem==5)return 1;
         else return 0;
    }
    int &ret=dp[pos][rem];
    if(ret!=(-1))return ret;
    ret=0;
    if(s[pos]!='?')
    {
        int x=s[pos]-'0';
        int y=n-pos-1;
        int val=(ten[y]*x)%13;
        rem=(rem+val)%13;
        ret=ad(ret,solve(pos+1,rem));
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            int y=n-pos-1;
            int val=(ten[y]*i)%13;
            int nw=(rem+val)%13;
            ret=ad(ret,solve(pos+1,nw));
        }
    }
    return ret;
}
void init()
{
    ten[0]=1;
    int dos=10;
    dos=dos%13;
    for(int i=1;i<=M;i++)
    {
        ten[i]=(dos*ten[i-1])%13;

    }
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    init();
    cin>>s;
    sz=s.size();n=sz;
    cout<<solve(0,0)<<endl;
    return 0;

}



































