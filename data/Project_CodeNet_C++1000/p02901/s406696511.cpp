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
int n,m;
int a[1002],b[1002];
int target;
int dp[1002][4100];
int solve(int pos,int msk)
{
    if(pos>m)
    {
        if(msk==target)return 0;
        else return inf ;
    }
    if(msk==target)return 0;
    int &ret=dp[pos][msk];
    if(ret!=(-1))return ret;
    ret=inf;
    ret=min(ret,a[pos]+solve(pos+1,msk | b[pos]));
    ret=min(ret,solve(pos+1,msk));
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    target=(1LL<<n)-1;
    f(i,1,m)
    {
        int x;
        cin>>a[i]>>x;
        f(j,1,x)
        {
            int y;
            cin>>y;y--;
            b[i]=b[i]|(1LL<<y);
        }
    }
    int ses=solve(1,0);
    if(ses>=inf)ses=-1;
    cout<<ses<<endl;
    return 0;

}



































