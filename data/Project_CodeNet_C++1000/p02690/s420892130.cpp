#include <iostream>

using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main() {
  ll x, a, b;
  cin >> x;
  
  rep(i,200) rep(j,400) {
    ll k = 200 - j;
    if(x == i*i*i*i*i - k*k*k*k*k) {
      a = i;
      b = k;
    }
  }
  
  cout << a << " " << b << endl;
  return 0;
}