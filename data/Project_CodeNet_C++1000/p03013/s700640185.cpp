#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int dp[100010];
const int mod = 1e9+7;

int main(){
   int n,m;
   cin >> n >> m;
   rep(i,m){
      int tmp;
      cin >> tmp;
      dp[tmp]= -1;
   }
   dp[0] = 1;
   rep(i,n){
      if (dp[i] == -1) continue;
      if (dp[i+1] != -1) {
         dp[i+1] += dp[i];
         dp[i+1] %= mod;
      }
      if (dp[i+2] != -1){
         dp[i+2] += dp[i];
         dp[i+2] %= mod;
      }
   }
   cout << dp[n] << endl;

  
  return 0;
}
