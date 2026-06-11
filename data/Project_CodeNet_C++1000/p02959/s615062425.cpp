#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n+1), b(n);
  rep(i, n+1) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll count = 0;
  rep(i, n)rep(j, 2){        
    if (a[i+j] > b[i]){
      a[i+j] -= b[i];
      count += b[i];
      b[i] = 0;
    }
    else {
      b[i] -= a[i+j];
      count += a[i+j];
      a[i+j] = 0;
    }
  }
  cout << count << endl;
  
  return 0;
}