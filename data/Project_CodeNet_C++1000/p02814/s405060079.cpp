#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

ll gcd(ll a, ll b){
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

ll even_count(ll x){
  ll count = 0;
  while(x % 2 == 0){
    count++;
    x /= 2;
  }
  return count;
}

int main(){
  ll n, m;
  cin >> n >> m;
  ll x = 1;
  ll a;
  bool flag = false;
  ll count;
  ll prev = -1;
  rep(i, n){
    cin >> a;
    a /= 2;
    x = lcm(x, a);
    if (prev == -1){
      prev = even_count(a);
      continue;
    }
    else{
      count = even_count(a);
      if (prev != count){
        flag = true;
        break;
      }
    }
  }
  if (flag)
    cout << 0 << endl;
  else{
    ll ans = (m + x) / (2 * x);
    cout << ans << endl;
  }
  
  return 0;
}