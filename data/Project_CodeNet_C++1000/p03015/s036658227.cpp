#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P pair<int,int>
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  string s;
  cin >> s;
  int n = s.size();
  vvint dp(n,vint(2));
  dp[0][0] = 2;
  dp[0][1] = 1;
  rep(i,1,n){
    if(s[i] == '0'){
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1]*3;
      dp[i][0] %= MOD;
      dp[i][1] %= MOD;
    }
    else{
      dp[i][0] = (dp[i-1][0])*2;
      dp[i][1] = dp[i-1][1]*3 + dp[i-1][0];
      dp[i][0] %= MOD;
      dp[i][1] %= MOD;
    }
  }
  
  cout << (dp[n-1][0] + dp[n-1][1])%MOD << endl;
}