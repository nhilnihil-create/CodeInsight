#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll power(ll x,ll n){
  if(!n) return 1;
  ll res = power(x * x % mod , n / 2);
  if(n & 1) res = res * x % mod;
  return res;
}

int main(){
  ll m,n;

  cin >> m >> n;
  cout << power(m,n) << endl;

  return 0;
}