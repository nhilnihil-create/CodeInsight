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
 
 
 
 
 
 
 













const int N=2005;
int u[N][N],l[N][N],r[N][N],d[N][N];
char s[N][N];
int main()
{
     int h,w;
     cin>>h>>w;
     string t;
     for(int i=1;i<=h;i++){
          cin>>t;
          for(int j=0;j<t.length();j++){
               s[i][j+1]=t[j];
          }
     }
     for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++){
               if(s[i][j]=='#'){l[i][j]=0;u[i][j]=0;}
               else {
                    l[i][j]=1+l[i][j-1];
                    u[i][j]=1+u[i-1][j];
               }
          }
     }
     for(int i=h;i>=1;i--){
          for(int j=w;j>=1;j--){
               if(s[i][j]=='#'){r[i][j]=0;d[i][j]=0;}
               else{
                    r[i][j]=1+r[i][j+1];
                    d[i][j]=1+d[i+1][j];
               }
          }
     }
    /* for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++)cout<<r[i][j]<<" ";
          cout<<"\n";
     }*/
     int mx=0;
     for(int i=1;i<=h;i++){
          for(int j=1;j<=w;j++){
               if(s[i][j]=='.'){
                    mx=max(mx,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
               }
          }
     }
     cout<<mx;
    
}























