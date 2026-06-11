#include<bits/stdc++.h>
using namespace std ; 
#define rep(i,N) for(int i = 0 ; i < (N) ; i++)

int main() {
  int N , M ; 
  cin >> N >> M ; 
  
  vector<bool> broken(N+1);
  
  rep(i,M){
    int a ; 
    cin >> a ; 
    broken.at(a) = 1 ; 
  }
  
  vector<int> dp(N+2) ;
  const int mod = 1000000007 ; 
  dp[N] = 1 ; 
  
  for(int i = N-1 ; i >=0 ; i--){
    if(broken.at(i)){
      dp.at(i) = 0 ; 
      continue ; 
    }
    dp.at(i) = (dp.at(i+1) + dp.at(i+2)) % mod ;
  }
  cout << dp.at(0) << endl ; 
  return 0 ; 

}