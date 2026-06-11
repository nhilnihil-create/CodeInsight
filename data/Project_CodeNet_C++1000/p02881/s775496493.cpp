#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll n; cin >> n;
  ll ans=INF_LL;
  for(ll i = 1;i*i<=n;i++){
    ll j;
    if(n%i==0)
      j = n/i;
    ans = min(ans,i+j-2);
  }
  
  cout << ans << endl;
  
  return 0;
}
