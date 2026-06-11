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
#define setbits(x)  __builtin_popcount(x)
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
     ll ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
 
 
 
 
 
 
 





int dp[1005][5005];
int main()
{
     int n,m;
     cin>>n>>m;
     vector<int> b(m,0);
     vector<int> cost(m);
     for(int i=0;i<m;i++){
          cin>>cost[i];
          int x;cin>>x;
          for(int j=0;j<x;j++){
               int y;cin>>y;
               b[i]|=(1<<(y-1));
          }
     }
     for(int i=0;i<=1000;i++){
          for(int j=0;j<=5000;j++)
          dp[i][j]=INT_MAX;
     }
     dp[0][0]=0;
     for(int i=0;i<m;i++){
          for(int j=0;j<(1<<n);j++){
               if(dp[i][j-(j&b[i])]!=INT_MAX)
               {dp[i+1][j]=dp[i][j-(j&b[i])]+cost[i];}
               dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
          }
          cout<<"\n";
     }
     int x=(1<<n)-1;
     if(dp[m][x]==INT_MAX)cout<<-1;
     else cout<<dp[m][x];
     
}






























