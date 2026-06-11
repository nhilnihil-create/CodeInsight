#include <iostream>
#include <vector>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<ll> color(3, 0);
  ll a;
  ll ans = 1;
  rep(i, n){
    cin >> a;
    ll count = 0;
    rep(j, 3){
      if (a == color[j]){
        count++;
      }
    }
    ans = ans * count % mod;
    rep(j, 3){
      if (a == color[j]){
        color[j]++;
        break;
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}