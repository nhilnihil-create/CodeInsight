#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;

ll dp[2010];
int main(){
  int s;
  cin >> s;
  dp[0] = 1;
  for (int i = 0; i <= s;i++){
    if (i-4 >= 0 ) dp[i] += dp[i-1];
    if (i-3 >= 0) dp[i] += dp[i-3];
    dp[i] %= mod;
  }
  cout << dp[s] << endl;

  return 0;
}