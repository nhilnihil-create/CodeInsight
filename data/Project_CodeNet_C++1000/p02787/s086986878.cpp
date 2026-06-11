#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
#define rep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

ll INF = 1ll << 60;

void llchmin(ll &a, ll b){
  if(a > b)
    a = b;
}
void llchmax(ll &a, ll b){
  if(a < b)
    a = b;
}

int main(){
  int h, n;
  cin >> h >> n;
  vi a(n), b(n);
  rep(i, 0, n){
    cin >> a[i] >> b[i];
  }
  
  ll dp[20020];
  rep(i, 0, 20020)
    dp[i] = 0;
  vector<bool> check(20020, false);
  check[0] = true;
  
  rep(i, 0, 10010){
    if(check[i] == false)
      continue;
    rep(j, 0, n){
      if(check[i+a[j]]){
        llchmin(dp[i+a[j]], dp[i]+b[j]);
      }
      else{
        dp[i+a[j]] = dp[i]+b[j];
        check[i+a[j]] = true;
      }
    }
  }
  
  ll ans;
  ans = -1;
  rep(i, h, 20020){
    if(check[i]){
      if(ans == -1)
        ans = dp[i];
      else
        llchmin(ans, dp[i]);
    }
  }
  
  cout << ans << endl;
  
  return 0;
  
}