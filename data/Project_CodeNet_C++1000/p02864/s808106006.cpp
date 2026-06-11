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
const int M=305;
int n,k;
int h[M];
int dp[M][M][M];
int solve(int pos,int last,int baki)
{
   if(pos>n)
   {
       return 0;
   }
   int &ret=dp[pos][last][baki];
   if(ret!=(-1))return ret;
   ret=0;
   int cost=h[pos]-h[last];
   cost=max(cost,0LL);
   ret=cost+solve(pos+1,pos,baki);
   if(baki>=1)ret=min(ret,solve(pos+1,last,baki-1));
   return ret;
}
 main()

{
    fast
    cin>>n>>k;
    f(i,1,n)
    {
        cin>>h[i];
    }
    memset(dp,-1,sizeof dp);
    int ses=solve(1,0,k);
    cout<<ses<<endl;
    return 0;

}



































