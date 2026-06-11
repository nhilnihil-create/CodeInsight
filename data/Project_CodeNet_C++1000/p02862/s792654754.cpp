#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
#define ll long long
#define MOD 1000000007
using namespace std;;
 
ll calc(ll a, ll b) {
  if (b ==0) return 1;
  if (b % 2 ==0) {
    ll d = calc(a,b/2);
    return(d*d) % MOD;
  }
  if (b % 2 ==1) return (a*calc(a,b-1)) % MOD;
}

ll combi(ll a, ll b) {
  ll ans=1, M = min(b,a-b);
  rep(i,0,M) {
    ans *= a - i; ans %= MOD;
  }
  rep(i,1,M+1) {
    ans *= calc(i,MOD-2) % MOD;
    ans %= MOD;
  }
  return ans;
}

int main() {
  ll X,Y,a,b; cin >> X >> Y;
  if (2 * Y - X >=0 && (2 * Y - X) % 3 ==0) {
    a = (2 * Y - X) / 3;
  } else {
    cout << 0 << endl; return 0;
  }
  if (2 * X - Y >=0 && (2 * X - Y) % 3 ==0) {
    b = (2 * X - Y) / 3;
  } else {
    cout << 0 << endl; return 0;
  }
  
  ll ans = combi(a+b,b);
  cout << ans << endl;
}