#include <iostream>
#include <queue>
#include <string>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main(){
  ll k;
  cin >> k;
  queue<ll> que;
  rep(i, 9) que.push(i+1);
  ll ans;
  rep(i, k){
    ll x = que.front();
    que.pop();
    if (x % 10 != 0) que.push(10 * x + (x % 10) - 1);
    que.push(10 * x + (x % 10));
    if (x % 10 != 9) que.push(10 * x + (x % 10) + 1);
    if (i == k - 1) ans = x;
  }
  cout << ans << endl;
  
  return 0;
}