///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=2009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int dp[M+5][M+5],n,a[M+5];
vector<pi>vec;
int solve(int pos,int lft)
{
    int total=pos-1;
    int lft_use=lft-1;
    int rgt_use=total-lft_use;
    int rgt=n-rgt_use;
    if(pos>n)return 0;
    int &ret=dp[pos][lft];
    if(ret!=(-1))return ret;
    ret=0;
    int cidx=vec[pos-1].si;
    int val=vec[pos-1].fi;
    int yo=abs(lft-cidx)*val;
    ret=solve(pos+1,lft+1)+yo;
    yo=abs(rgt-cidx)*val;
    ret=max(ret,solve(pos+1,lft)+yo);
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
        vec.pb(mp(a[i],i));
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    int ses=solve(1,1);
    cout<<ses<<endl;
    return 0;

}











