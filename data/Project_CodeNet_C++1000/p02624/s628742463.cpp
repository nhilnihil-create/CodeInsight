#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  ll n;
  cin >> n;
  vector<ll> v(n+1,1);

  for (ll i = 2;i <= n;i++){
    for (ll j = i;j <= n;j+=i) v[j]++;
  }
  //rep(i,n){
  //  cout << i+1 << ":" << v[i+1] << endl;
  //}
  ll ans = 0;
  for (int i = 1;i <= n;i++){
    ans += ll(i)*v[i];
  }
  cout << ans << endl;

}
