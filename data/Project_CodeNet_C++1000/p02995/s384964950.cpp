#include <iostream>
#include <string>
using ll = long long;
using namespace std;

ll gcd(ll a, ll b){
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll e = lcm(c, d);
  ll count = 0;
  count += b / c;
  count += b / d;
  count -= b / e;
  count -= (a-1) / c;
  count -= (a-1) / d;
  count += (a-1) / e;
  ll ans = b - a + 1 - count;
  cout << ans << endl;
  
  return 0;
}