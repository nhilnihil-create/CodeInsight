#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
  string s;cin >> s;reverse(s.begin(),s.end());
  ll n = s.size(),i,j,k,z,f = 1,dp[n+1][13] = {};dp[0][0] = 1;
  for(i=0;i<n;i++){
    if('0'<=s[i] && s[i]<='9'){
      z = s[i]-'0';
      for(j=0;j<13;j++) dp[i+1][(j+z*f)%13] = (dp[i+1][(j+z*f)%13]+dp[i][j])%mod;
    } else {
      for(k=0;k<10;k++){
        for(j=0;j<13;j++) dp[i+1][(j+k*f)%13] = (dp[i+1][(j+k*f)%13]+dp[i][j])%mod;
      }
    }
    f = (f*10)%13;
  }
  cout << dp[n][5] << "\n";
}