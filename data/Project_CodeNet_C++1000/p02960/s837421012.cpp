#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  string s;
  cin >> s;
  ll si = s.size();
  vector<vector<ll>> dp(si,vector<ll>(13));
  for(int i = 0;i < si;i++)for(int j = 0;j < 13;j++)dp[i][j] = 0;
  for(int i = 0;i < 13;i++){
    if(s[0] == '?'){
      if(i <= 9)dp[0][i] = 1;
      else dp[0][i] = 0;
      //cout << "A" << endl;
    }
    else{
      if((int)s[0] - '0' == i)dp[0][i] = 1;
      else dp[0][i] = 0;
    }
  }
  
  ll mod = pow(10,9) + 7;
  for(int i = 1;i < si;i++){
    for(int j = 0;j < 13;j++){
      if(s[i] == '?'){
        //cout << "B" << endl;
        for(int k = 0;k < 10;k++){
          ll nowmod = j*10 + k;
          nowmod %= 13;
          dp[i][nowmod] += dp[i - 1][j];
          dp[i][nowmod] %= mod;
        }
      }
      else{
        ll nowmod2 = j*10 + (int)(s[i] - '0');
        nowmod2 %= 13;
        dp[i][nowmod2] += dp[i - 1][j];
        dp[i][nowmod2] %= mod;
      }
    }
  }
  cout << dp[si - 1][5] << endl;
}