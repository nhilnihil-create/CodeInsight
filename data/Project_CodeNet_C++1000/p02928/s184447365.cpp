#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod = 1e9+7;
int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<int> v(n);
  ll ans = 0;
  rep(i,n) cin >> v[i];
  rep(i,n){
    for (int j = i+1; j < n;j++){
      if (v[i] > v[j]) ans++;
    }
  }
  ans *= k;
  ans %= mod;
  sort(v.begin(),v.end());
  rep(i,n){
    ll tmp = k*(k-1)/2;
    tmp%=mod;
    ans += (tmp*ll(lower_bound(v.begin(),v.end(),v[i])-v.begin()));
    ans%=mod;
  }
  cout << ans << endl;

  return 0;
  
}
