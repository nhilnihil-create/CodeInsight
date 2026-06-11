#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long int;

template< typename T >
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll x, y;
    ll gcd = extgcd(a, b, x, y);
    ll ans = 1;
    for(ll i = 2; i * i <= gcd; i++){
        if (gcd % i != 0)continue;
        ans++;
        while(gcd % i == 0){
            gcd /= i;
        }
    }
    if (gcd > 1LL)ans++;
    cout << ans << endl;
}