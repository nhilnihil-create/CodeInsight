#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod=1000000007;
/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int main() {
ll h,n;
cin>>h>>n;
ll a[n]={}, b[n]={};
rep(i,n){ cin>>a[i]>>b[i];}
ll ca=0;
vector<vector<ll>> dp(n+1, vector<ll>(100000, 1000000000000));
dp[0][0]=0;
rep(i,n){
rep(j,100000){
dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
if(j-a[i]>=0){
dp[i+1][j]=min(dp[i+1][j],dp[i+1][j-a[i]]+b[i]);}
}}
//rep(i,n+1)rep(j,h+1) cout << i << " " << j << " " << dp[i][j] << endl;
ll ans = 10000000000;
repl(i,h,50000) ans = min(ans,dp[n][i]);
cout << ans << endl;}
