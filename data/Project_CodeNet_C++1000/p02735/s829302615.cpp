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
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int h,w;
string s[105];
int dp[105][105][2];
int solve(int x,int y,int last)
{
      if(x<0 || y<0 || x>=h || y>=w)return inf;
      if(x==h-1 && y==w-1)
      {
          if(last==1 || s[x][y]=='#')return 1;
          else return 0;
      }
      int &ret=dp[x][y][last];
      if(ret!=(-1))return ret;
      int ad=0;
      if(last==0)
      {
           if(s[x][y]=='#')
           {
               ret=min(solve(x+1,y,1),solve(x,y+1,1));
           }
           else if(s[x][y]=='.')
           {
               ret=min(solve(x+1,y,0),solve(x,y+1,0));
           }
      }
      else if(last==1)
      {
           if(s[x][y]=='#')
           {
                ret=min(solve(x+1,y,1),solve(x,y+1,1));
           }
           else
           {
              ret=min(solve(x+1,y,0),solve(x,y+1,0))+1;
           }
      }
      return ret;
}
 main()
{
    fast
    memset(dp,-1,sizeof dp);
    cin>>h>>w;
    f(i,0,h-1)
    {
         cin>>s[i];
    }
    int nd=h-1+w-1+1;
    int tmp=0;
    if(s[0][0]=='#')tmp=1;
    int ses=min(solve(1,0,tmp),solve(0,1,tmp));
    cout<<ses<<endl;
    return 0;
}
