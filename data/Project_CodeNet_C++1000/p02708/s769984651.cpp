#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  ll n,k;
  cin >> n >> k;
  ll ans = 0;
  for(ll i=k;i<=n+1;i++){
    ll r = i*(2*n-i+1)/2;
    ll l = i*(i-1)/2;
    ans+=r-l+1;
    ans%=MOD;
  }
  cout << ans << endl;
  return 0;
}
