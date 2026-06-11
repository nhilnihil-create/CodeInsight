#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;


const ll INF = 1e16;
const ll mod = 1e9 + 7;
//const ll MOD = 998244353;

ll DPFibonacci(int x){
  int dp[100010] = {0};
  dp[0] = 0;
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
  vector<ll> a(m+1);
  rep(i,m+1) cin >> a[i];
  a[m]=n+1;
  ll ans = 1;
  int pos=0;
//  cout << a[0] << endl;
  for (ll i = 0; i < m+1; i++) {
//    cout << a[i] << ' ' <<pos << endl;
    if (pos -a[i] ==0) {
      cout << 0 << endl;
      return 0;
    }
    else if(a[i]-pos ==1||a[i]-pos ==2) ans = ans;
    else{
      int dif_a=a[i]-pos;
//      cout << dif_a << endl;
//      cout << DPFibonacci(dif_a) << endl;
      ans = ans* DPFibonacci(dif_a);
      ans %=mod;
//      cout << ans << endl;
    }
    pos=a[i]+1;
//    cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
