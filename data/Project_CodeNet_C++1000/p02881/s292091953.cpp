#include <iostream>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  ll x = 0;
  ll y = 100000000000000;
  rep2(i, 1, sqrt(n)+1){
    if (n % i == 0){
      if (i + n/i < x + y){
        x = i;
        y = n/i;
      }
    }
  }
  cout << x + y - 2 << endl;
  
  return 0;
}