#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

int main(){
  string S;
  cin >> S;
  
  int dp[200010];
  int n = S.size();
  dp[n] = 0;
  int p = 2019;
  
  int n_10[200010];
  n_10[0] = 1;
  
  rep(i, 0, n){
    n_10[i+1] = n_10[i]*10%p;
  }
  
  int cnt[p];
  rep(i, 0, p)
    cnt[i] = 0;
  cnt[0]++;
  
  rep(i, 1, n+1){
    char c = S[n-i];
    int a = c - '0';
    
    dp[n-i] = dp[n-i+1] + (a * n_10[i-1] % p);
    dp[n-i] %= p;
    cnt[dp[n-i]]++;
  }
  
  ll ans = 0;
  
  rep(i, 0, p){
    int m = cnt[i];
    ans += m*(m-1)/2;
  }
  
  cout << ans << endl;
  
  return 0;
  
}