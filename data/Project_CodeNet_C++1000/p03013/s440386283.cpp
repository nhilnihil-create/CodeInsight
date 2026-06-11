#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}



int main(){
  ll n,m; cin >> n >> m;
  vector<ll> dp(n+1); vector<bool> isbreak(n+1);
  
  rep(i,m){
    ll x; cin >> x;
    isbreak[x] = true;
  }
  
  if(n == 1){
    if(isbreak[1]) cout << 0 << endl;
    else cout << 1 << endl;
  }
  else{
    
  if(isbreak[1] && isbreak[2]){
    cout << 0 << endl;
    return 0;
  }
  else if(isbreak[1] && !isbreak[2]){
    dp[1] = 0; dp[2] = 1;
  }
  else if(!isbreak[1] && isbreak[2]){
    dp[1] = 1; dp[2] = 0;
  }
    else{
      dp[1] = 1; dp[2] = 2;
    }
    
    
    for(ll i=3; i <= n; i++){
      if(isbreak[i]){
        continue;
      }
      else{
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = mod(dp[i]);
      }
    }
    
    cout << dp[n] << endl;
  }
  
}
  