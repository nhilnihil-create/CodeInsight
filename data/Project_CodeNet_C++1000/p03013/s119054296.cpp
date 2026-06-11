#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int DPFibonacci(int x, vector<bool> v){
  ll dp[1000010] = {0};
  dp[0] = 1;
  for(int i = 1; i < x+1; i++){
    if(v[i] == false){
      dp[i] = 0; continue;
    }
    if(i==1 && v[1] == true){ dp[1] = 1; continue; }
	dp[i] = dp[i-1] + dp[i-2];  //cout << dp[i] << endl;
    dp[i] %= 1000000007;
  }
  return dp[x];
}

int main() {
  int n,m; cin >> n >> m;
  vector<bool> v(1000010,true);
  rep(i, m){
    int c; cin >>c;
    v[c] = false;
  }
  
  cout << DPFibonacci(n, v) << endl;
  
}