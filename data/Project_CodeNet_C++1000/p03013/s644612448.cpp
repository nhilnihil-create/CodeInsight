#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;


const ll INF = 1e16;
const ll mod = 1e9 + 7;
//const ll MOD = 998244353;

ll DPFibonacci(int x){
  int dp[100000] = {0};
  dp[0] = 1;
  dp[1] = 1;
  for(int i = 2; i < x+1; i++){
    dp[i] = (dp[i-1] + dp[i-2]);
    dp[i] %= mod;
  }
  return dp[x];
}

int main() {
  ll n, m;
  cin >> n >> m;
  if(m==0){
   cout << DPFibonacci(n) << endl;
   return 0;
  }
  vector<ll> a(m);
  rep(i,m) cin >> a[i];
  ll ans = DPFibonacci(a[0]-1);ans%=mod;

//  cout << a[0] << endl;
  int pos=a[0]+2;
  for (ll i = 1; i < m; i++) {
//    cout << a[i] << ' ' <<pos << endl;
    if(a[i]-a[i-1] ==1) {
      cout << 0 << endl;
      return 0;
    }
    else{
//      cout << dif_a << endl;
//      cout << DPFibonacci(dif_a) << endl;
      ans = ans* DPFibonacci(a[i]-pos);
      ans %=mod;
//      cout << ans << endl;
    }
    pos=a[i]+2;
//    cout << ans << endl;
  }
  ans = ans* DPFibonacci(n-a[m-1]-1);
  ans %= mod;
  cout << ans << endl;
  return 0;
}
