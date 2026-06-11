#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define mod 998244353
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n, 0);
  ll max = 0;
  for(ll i=0; i<n; i++){
    ll num;
    cin >> num;
    if(max < num) max = num;
    if(i == 0 && num != 0){
      cout << 0 << endl;
      return 0;
    }
    vec[num]++;
  }
  if(vec[0] != 1){
    cout << 0 << endl;
    return 0;
  }
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  ll res = 1;
  for(ll i=0; i<=max-1; i++){
    ll powRes = 1;
    for(ll j=0; j<vec[i+1]; j++){
      powRes *= vec[i];
      powRes %= mod;
    }
    res *= powRes;
    res %= mod;
  }
  cout << res << endl;
}
  
  