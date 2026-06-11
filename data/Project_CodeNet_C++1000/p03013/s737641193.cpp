#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<bool> nb(n+10,true);
  
  
  REP(i,m){
    int a;
    cin >> a;
    nb[a] = false; 
  }
  
  ll dp[n+10];
  REP(i,n+10){
    dp[i] = 0;
  }
  
  //cout << n << endl;
  dp[0] = 1;
  dp[1] = 1;
  ll mod = 1000000007;
  
  REP(i,n){
    if(nb[i]){
      if(nb[i+1]){
        dp[i+2] += dp[i] + dp[i+1];
        dp[i+2] %= mod; 
      }
      else{
        dp[i+2] += dp[i];
        dp[i+2] %= mod;   
      }
    }
    else{
      if(nb[i+1]){
        dp[i+2] += dp[i+1];
        dp[i+2] %= mod; 
      }
      else{
        cout << 0 << endl;
        return 0;  
      }
    }    
  }

  
  cout << dp[n] << endl;


}