#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
#define mod 1000000007
#define mod2 998244353 
#define PI 3.14159265
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define vi vector<ll>
#define sz size()
#define fi first
#define se second
#define lz length()
#define all(x) (x).begin(),(x).end()
#define scf(x) scanf("%lld",&x)
#define rep(i,n) for(ll i=0;i<n;i++)
const int INF = (int)1e9;
const ll IINF=1LL<<62;
const int maxn=10000005;

//int divr[maxn];
/**/
/*void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}*/
 
/*const int N=1000005;
ll n;
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};
vector<pair<pi,ll>> rect;
deque<line> dq;
*/
ll modexpo(ll a,ll b)
{
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}
 
 
 
 
 
 
 







int dp[200][200];

int main()
{
     int h,w;
     cin>>h>>w;
     char s[h+2][w+2];
     for(int i=0;i<=h+1;i++){
          for(int j=0;j<=w+1;j++)s[i][j]='.';
     }
     for(int i=1;i<=h;i++){
          string t;cin>>t;
          for(int j=0;j<t.length();j++){
               s[i][j+1]=t[j];
          }
     }
     for(int j=1;j<=w;j++){
          if(s[1][j]=='.')dp[1][j]=dp[1][j-1];
          else if(s[1][j]=='#'){
               if(s[1][j-1]=='.')dp[1][j]=1+dp[1][j-1];
               else dp[1][j]=dp[1][j-1];
          }
     }
     for(int i=1;i<=h;i++){
          if(s[i][1]=='.')dp[i][1]=dp[i-1][1];
          else if(s[i][1]=='#'){
               if(s[i-1][1]=='.')dp[i][1]=1+dp[i-1][1];
               else dp[i][1]=dp[i-1][1];
          }
     }
     for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++){
               if(i==1||j==1)continue;
               if(s[i][j]=='.'){
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
               }
               else if(s[i][j]=='#'){
                    if(s[i][j-1]=='.'&&s[i-1][j]=='.'){
                         dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
                         
                    }
                    else if(s[i][j-1]=='.'&&s[i-1][j]=='#'){
                         dp[i][j]=min(1+dp[i][j-1],dp[i-1][j]);
                    }
                    else if(s[i][j-1]=='#'&&s[i-1][j]=='.'){
                         dp[i][j]=min(dp[i][j-1],1+dp[i-1][j]);
                    }
                    else{
                         dp[i][j]=min(dp[i][j-1],dp[i-1][j]);
                    }
               }
          }
     
     }
     /*for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++)cout<<dp[i][j]<<" ";
          cout<<"\n";
     }*/
     cout<<dp[h][w];
}
























