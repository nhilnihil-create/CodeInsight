#include <bits/stdc++.h>
//#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<double,double> P;
const ll INF = 4*1e18;
const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

int n,m,s[2100],t[2100],dp[2100][2100];
signed main(){
  cin>>n>>m;
  rep(i,n)cin>>s[i+1];
  rep(j,m)cin>>t[j+1];
  rep(i,n+1)dp[i][0] = 1;
  rep(i,m+1)dp[0][i] = 1;
  repd(i,1,n+1){
    repd(j,1,m+1){
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
      if(s[i] != t[j])dp[i][j] = (dp[i][j] - dp[i-1][j-1] + MOD) % MOD;
    }
  }
  cout << dp[n][m] << endl;
}
