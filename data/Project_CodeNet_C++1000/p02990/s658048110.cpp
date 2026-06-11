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
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}
 
 
 
 
 
 
 







int dp[2005][2005];
int f[2005];
int main()
{
    for(int i=0;i<=2000;i++)dp[0][i]=0;
    for(int i=0;i<=2000;i++)dp[i][0]=1;
    for(int i=1;i<=2000;i++){
         for(int j=1;j<=i;j++){
              dp[i][j]=(1LL*dp[i-1][j]+dp[i-1][j-1])%mod;
         }
    }
    f[0]=1,f[1]=1;
    for(int i=2;i<=2000;i++){
         f[i]=(1LL*f[i-1]*i)%mod;
    }
    
    int n,k;
    cin>>n>>k;
    int r=n-k+1;
    for(int i=1;i<=r&&i<=k;i++){
        ll res=(1LL*dp[r][i]*dp[k-1][i-1])%mod;
         cout<<res<<"\n";
    }
    if(r<k){
         while(r!=k){cout<<0<<"\n";r++;}
    }
}
























