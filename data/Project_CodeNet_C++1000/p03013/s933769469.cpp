#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,m;
  cin >> n >> m;

  static int dp[100001] = {0};
  rep(i,m){
    int a;
    cin >> a;
    dp[a] = -1;
  }
  dp[0] = 1;
  rep(i,n+1){

    if(dp[i] == -1) continue;
    
    int ni = i + 1;
    if(ni > n) continue;
    if(dp[ni] != -1) dp[ni] += dp[i];
    dp[ni] = dp[ni]%1000000007;

    int nni = i + 2;
    if(ni > n) continue;
    if(dp[nni] != -1) dp[nni] += dp[i];
    dp[nni] = dp[nni]%1000000007; 
  }
  cout << dp[n] << endl;
}