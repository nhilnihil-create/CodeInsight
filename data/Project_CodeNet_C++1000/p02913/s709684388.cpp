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

int dp[5050][5050];

signed main(){
  int n;
  string s;
  cin >> n >> s;
  rrep(i,n-1,0){
    rrep(j,n-1,0){
      if(s[i] != s[j]) dp[i][j] = 0;
      else{
        dp[i][j] = dp[i+1][j+1]+1;
      }
    }
  }
  int ans = 0;
  rep(i,0,n){
    rep(j,0,n){
      if(j < i) continue;
      int n = min(dp[i][j],j-i);
      ans = max(ans,n);
    }
  }
  cout << ans << endl;
}