#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll h,n;
  cin>>h>>n;
  vl a(n+1);
  vl b(n+1);
  for(ll i=1;i<=n;i++){
    cin>>a[i]>>b[i];
  }
  ll dp[n+1][h+1];
  dp[0][0]=0;
  for(ll i=1;i<=h;i++){
    dp[0][i]=INF;
  }
  for(ll i=1;i<=n;i++){
    rep(j,a[i]){
      if(dp[i-1][j]>b[i]){
        dp[i][j]=b[i];
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
      if(j==h){
        break;
      }
    }
    for(ll j=a[i];j<=h;j++){
      if(dp[i-1][j]>dp[i][j-a[i]]+b[i]){
        dp[i][j]=dp[i][j-a[i]]+b[i];
      }
      else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  print(dp[n][h]);
}