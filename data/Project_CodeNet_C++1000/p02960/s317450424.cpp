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
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  string s;
  cin >> s;
  int l = s.size();
  vint dp(13);
  dp[0] = 1;
  int mul = 1;
  rrep(i,l-1,0){
    vint ndp(13);
    if(s[i] == '?'){
      rep(s,0,10){
        rep(j,0,13){
          ndp[(j + mul*s)%13] += dp[j];
          ndp[(j + mul*s)%13] %= MOD;
        }
      }
    }
    else{
      int m = s[i] - '0'; 
      rep(j,0,13){
        ndp[(j + mul*m)%13] += dp[j];
        ndp[(j + mul*m)%13] %= MOD;
      }
    }
    dp = ndp;
    mul *= 10;
    mul %= 13;
  }
  cout << dp[5] << endl;
}