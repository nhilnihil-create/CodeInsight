#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define MOD1 1000000007
int main(){
  ll n,m,k,i,j;
  ll dp[100010][13]={0};
  string s;
  cin >> s;
  n = s.size();
  dp[0][0]=1;
  rep(i,n){
    rep(j,13){
      if(s[i]=='?'){
        rep(k,10){
          dp[i+1][(j*10+k)%13] += dp[i][j];
          dp[i+1][(j*10+k)%13] %= MOD1;
        }
      }else{
        k = (ll)(s[i]-'0');
        dp[i+1][(j*10+k)%13] += dp[i][j];
        dp[i+1][(j*10+k)%13] %= MOD1;
      }
    }
  }
  cout << dp[n][5] << endl;
  return 0;
}