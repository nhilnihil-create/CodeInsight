#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

ll dp[100010][13];


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  string s;
  cin >> s;
  int n = s.size();
  
  memset(dp, 0, sizeof(dp));
  
  dp[0][0] = 1;
  rep(i,n){
    rep(j,13){
      if(s[i] == '?'){
        rep(k,10){
          dp[i+1][(j*10+k)%13] += dp[i][j];
          dp[i+1][(j*10+k)%13] %= MOD;
        }
      }
      else{
        int k = s[i] -'0';
        dp[i+1][(j*10+k)%13] += dp[i][j];
        dp[i+1][(j*10+k)%13] %= MOD;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}
