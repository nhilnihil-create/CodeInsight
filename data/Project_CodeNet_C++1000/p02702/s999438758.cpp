#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, s, n) for (ll i = s; i < (n); i++)
#define repr(i, n) for (ll i = n-1; i >= 0; i--)
using namespace std;

const int mod = 2019;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(n+1);
  vector<int> count(mod, 0);
  dp[n] = 0;
  count[0]++;
  int x = 1;
  repr(i, n){
    int num = (s[i] - '0');
    num = (num * x) % mod;
    x = (x * 10) % mod;
    dp[i] = (dp[i+1] + num) % mod;
    count[dp[i]]++;
  }
  int ans = 0;
  rep(i, mod){
    ans += count[i] * (count[i] - 1) / 2;
  }
  cout << ans << endl;
  
  return 0;
}
