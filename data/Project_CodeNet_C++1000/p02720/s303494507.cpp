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
 
 
 
 
 
 
 









int main()
{
     int k;
     cin>>k;
     if(k<=9)cout<<k;
     else
     {
          int i=9;
          queue<ull> q;
          for(int i=1;i<=9;i++)q.push(i);
          ull ans=0;
          while(true){
               ull p=q.front();q.pop();
               ull d=p%10;
               p*=10;
               
               if(d!=0)
               {i++;
               ans=p+d-1;if(i==k)break;q.push(ans);
               }
               ans=p+d;
               i++;
               if(i==k)break;q.push(ans);
               if(d!=9){
                    i++;
                    ans=p+d+1;
                    if(i==k)break;q.push(ans);
               }
          }
          cout<<ans;
     }
}
























