#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

const ll mod = 1000000007;
int main(){
  ll n;
  cin >> n;
  vector<ll> zero(61, 0);
  vector<ll> one(61, 0);
  rep(i, n){
    ll a;
    cin >> a;
    rep(j, 61){
      if (a % 2 == 0) zero[j]++;
      else one[j]++;
      a /= 2;
    }
  }
  
  ll ans = 0;
  ll two = 1;
  rep(i, 61){
    ll add = (zero[i] * one[i]) % mod * two;
    ans = (ans + add) % mod;
    two = (two * 2) % mod;
  }
  cout << ans << endl;
  
  return 0;
}