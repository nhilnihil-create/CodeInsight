#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve(){
  string s; cin >> s;
  int n = s.size();
  ll mod = 1000000007;
  vector<ll> dp(13, 0);
  dp[0] = 1;
  ll ten = 1;
  for(int i = n - 1; i >= 0; i--){
    vector<ll> dp2(13, 0);
    for(int j = 0; j < 13; j++){
      ll x = dp[j];
      if(s[i] != '?'){
        int num = s[i] - '0';
        num = (num * ten) % 13;
        dp2[(j + num) % 13] = (dp2[(j + num) % 13] + x) % mod;
      }
      else{
        for(int k = 0; k <= 9; k++){
          int num = (k * ten) % 13;
          dp2[(j + num) % 13] = (dp2[(j + num) % 13] + x) % mod;
        }
      }
    }
    ten = (ten * 10) % 13;
    dp = dp2;
  }
  cout << dp[5] << endl;
  return;
}

int main(){
  solve();
  return 0;
}
