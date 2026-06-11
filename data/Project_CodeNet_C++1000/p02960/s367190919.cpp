#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const ll INF = 1e18 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  string s;
  cin >> s;
  ll dp[110000][13];
  for(int i = 0; i < 110000; i++){
    fill(dp[i], dp[i] + 13, 0);
  }
  if(s.at(0) == '?') fill(dp[0], dp[0] + 10, 1);
  else dp[0][s.at(0) - '0'] = 1;
  
  for(ll i = 1; i < s.size(); i++){
    if(s.at(i) != '?'){
      ll k = s.at(i) - '0';
      for(ll j = 0; j < 13; j++){
        dp[i][(10*j + k)%13] = dp[i-1][j];
      }
    }else{
      for(ll j = 0; j < 13; j++){
        for(ll k = 0; k <= 9; k++){
          dp[i][(10*j+k)%13] += dp[i-1][j];
          dp[i][(10*j+k)%13] %= MOD;
        }
      }
    }
  }
  cout <<dp[s.size() - 1][5] % MOD<<endl;
}