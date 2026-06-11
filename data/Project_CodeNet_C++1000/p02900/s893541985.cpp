#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

ll gcd(ll a, ll b){
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

int main(){
  ll a, b;
  cin >> a >> b;
  ll n = gcd(a, b);
  ll x = n;
  ll ans = 1;
  rep2(i, 2, sqrt(n)+2){
    if (x % i == 0) ans++;
    while(x % i == 0){
      x /= i;
    }
  }
  if (x != 1) ans++;
  cout << ans << endl;
  
  return 0;
}