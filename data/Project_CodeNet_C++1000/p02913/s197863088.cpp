#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  int n;
  string s;
  cin >> n >> s;
  vvi dp(n,vi(n));
  rep(i,n) dp[n-1][i] = (s[i] == s[n-1]);
  for(int i=n-2;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(j > i) dp[i][j] = dp[j][i];
      else{
        if(s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
        else dp[i][j] = 0;
      }
    }
  }
  int ans = 0;
  rep(i,n){
    rep(j,n){
      ans = max(ans, min(abs(j-i),dp[i][j]));
    }
  }
  cout << ans << endl;
}
