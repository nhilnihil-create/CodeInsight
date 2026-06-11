#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const int INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[100005][2];

int main(){
  string s;
  cin >> s;
  int n = int(s.size());
  dp[0][0] = 1;
  rep(i,n){
    //a+b = 0
    if(s[i]=='0'){
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = dp[i][1];
    }else{
      dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
    }
    //a+b = 1
    if(s[i]=='0'){
      (dp[i+1][1] += dp[i][1]*2%mod) %= mod;
    }else{
      (dp[i+1][0] += dp[i][0]*2%mod) %= mod;
      (dp[i+1][1] += dp[i][1]*2%mod) %= mod;
    }
  }
  cout << (dp[n][0] + dp[n][1]) % mod << endl;
  return 0;
  
}