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
const int M=1000009;
int dp[M][2];
string s;
int sz;
int solve(int pos,int carry)
{
    if(pos==(sz-1))
    {
        if(carry==1)return 1;
        else return 0;
    }
    int &ret=dp[pos][carry];
    if(ret!=(-1))return ret;
    ret=inf;
    int x=s[pos]-'0';
    int cost;
    if(carry==1)
    {
         int niche=x+1;
         for(int i=niche;i<=9;i++)
         {
               cost=i+(i-niche)+solve(pos+1,0);
               ret=min(ret,cost);
         }
         for(int i=0;i<niche;i++)
         {
             cost=solve(pos+1,1)+i+(i+10-niche);
             ret=min(ret,cost);
         }
    }
    else
    {
         int niche=x;
          for(int i=niche;i<=9;i++)
         {
               cost=i+(i-niche)+solve(pos+1,0);
               ret=min(ret,cost);
         }
         for(int i=0;i<niche;i++)
         {
             cost=solve(pos+1,1)+i+(i+10-niche);
             ret=min(ret,cost);
         }
    }
    return ret;
}
 main()

{
    fast
    memset(dp,-1,sizeof dp);
    cin>>s;
    reverse(s.begin(),s.end());
    s+="0";
    sz=s.size();
    int ses=solve(0,0);
    cout<<ses<<endl;
    return 0;

}



































