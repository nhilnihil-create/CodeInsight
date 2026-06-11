#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;

int main(){
  ll n,k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = k;i <= n+1;i++){
    ans += (i*(2*n-i+1)/2 - i*(i-1)/2 +1);
    ans %= mod;
  
    //ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
