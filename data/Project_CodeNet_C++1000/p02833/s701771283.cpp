#include<bits/stdc++.h>
using namespace std;
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
int divr[maxn];
/*ll modexpo(ll a,ll b)
{
     ll res=1LL;
     while(b>0)
     {
          if(b&1)res=(res*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return res;
}*/
void divisor()
{for(int i=2;i<sqrt(maxn);i++)
     {
          if(!divr[i])
          {
               for(int j=i*i;j<maxn;j+=i)if(!divr[j])divr[j]=i;     
          }
     }
     for(int i=1;i<maxn;i++)if(!divr[i])divr[i]=i;
}
 
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
 
 
 
 
 






ll calc(ll num,ll pr)
{
     ll res=0LL;
     ll t=pr;
     while((num/t)>0)
     {
          res+=num/t;
          t*=pr;
     }
     return res;
}







int main()
{
     ll n;
     cin>>n;
     ll ct2=0,ct5=0;
     ct2=calc(n/2,2LL);
     ct5=calc(n/2,5LL);
     if(n&1)
     {
          ll oct2=calc(n,2LL);
          ll oct5=calc(n,5LL);
          ll to2=max(0LL,oct2-ct2-n/2);
          ll to5=max(0LL,oct5-ct5);
          ll ans=min(to2,to5);
          cout<<ans;
     }
     else{
          ll ct10=min(ct2+n/2,ct5);
          cout<<ct10;
     }
     
     
}



















 
 
 
 
 















