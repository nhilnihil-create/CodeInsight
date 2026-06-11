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
/*int find(int a){
     if(a==par[a])return a;
     return par[a]=find(par[a]);
}
void unite(int a,int b){
     a=find(a),b=find(b);
     if(a==b)return ;
     par[b]=a;
}
ll modexpo(ll a,ll b)
{
     int ans=1LL;
     while(b>0)
     {
          if(b&1)ans=(ans*a)%mod;
          a=(a*a)%mod;
          b>>=1;
     }
     return ans;
}
*/












queue<int> a[100005];
queue<pair<pair<int,int>,int>> q;
int vis[100005];
int main(){
     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
          for(int j=0;j<n-1;j++){
               int x;cin>>x;a[i].push(x);
          }
     }
     for(int i=1;i<=n;i++){
          int x=a[i].front(),y=a[x].front();
          if(vis[x]||vis[y])continue;
          if(y==i){
               q.push({{x,y},1});vis[x]=1,vis[y]=1;
          }
     }
     int res=0;
     while(!q.empty()){
          int x=q.front().fi.fi,y=q.front().fi.se,val=q.front().se;
          res=max(res,val);
          a[x].pop();a[y].pop();q.pop();
          int u=-1,v=-1;
          if(!a[x].empty())u=a[x].front();
          if(!a[y].empty())v=a[y].front();
          if(u!=-1&&a[u].front()==x){
               q.push({{x,u},val+1});
          }
          if(v!=-1&&a[v].front()==y){
               q.push({{y,v},val+1});
          }

     }
     bool flag=true;
     for(int i=1;i<=n;i++){
          if(!a[i].empty()){flag=false;break;}
     }
     if(!flag)cout<<-1;
     else cout<<res;

}

















































