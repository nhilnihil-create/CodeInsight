#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n,k;
  cin >> n >> k;
  n++;
  ll ans=0;
  for(ll i=k; i<=n; i++){
    ll minsom = (1+i)*i/2;
    ll maxsom = (2*n-i+1)*i/2;
    ans += maxsom - minsom +1;
    if(ans >= 1000000007) ans%=1000000007;
  }
  cout << ans << endl;
}
