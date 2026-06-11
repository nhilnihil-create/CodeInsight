#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[1000005];

signed main(){
  
  int k;
  cin >> k;
  
  dp[1] = 7 % k;
  
  for(int i=2;i<1000005;i++) dp[i] = ( dp[i-1] * 10 + 7 ) % k;
  
  for(int i=1;i<1000005;i++){
    if( dp[i] == 0 ){
      cout << i << endl;
      return 0;
    }
  }
  
  cout << -1 << endl;
  
  return 0;
}
