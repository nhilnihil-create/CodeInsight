#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[305][305][305];//見ている場所,スキップした回数,最後にスキップした場所
int main(){
for(int i=0;i<305;i++)for(int j=0;j<305;j++)for(int k=0;k<305;k++)dp[i][j][k]=inf;
ll n,d;
cin>>n>>d;
n++;
V<ll> a(n);
for(int i=1;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++)dp[i+1][i][0]=0;
for(int i=0;i<=d;i++){
  for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
          if(j>=k)continue;
          if(a[k]-a[j]>0&&i>=k-j-1)chmin(dp[k+1][i][k],dp[j+1][i-(k-j-1)][j]+a[k]-a[j]);
          else if(i>=k-j-1)chmin(dp[k+1][i][k],dp[j+1][i-(k-j-1)][j]);
          chmin(dp[k+1][i+1][j],dp[k][i][j]);
      }
  }
}
ll ans=inf;
for(int i=0;i<=d;i++)for(int j=0;j<n;j++)chmin(ans,dp[n][i][j]);
cout<<ans<<endl;
}