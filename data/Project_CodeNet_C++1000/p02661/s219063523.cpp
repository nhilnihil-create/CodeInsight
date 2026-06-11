#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
  
  ll n;
  cin >> n;
  
  vector<ll> a, b;
  
  for ( ll i = 0; i < n; i++ ){
    ll x, y;
    cin >> x >> y;
        
    a.push_back(x);
    b.push_back(y);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  ll ans = 0;
  ll l, r;
    
  if ( n % 2 == 0 ){
    l = a[n/2 - 1] + a[n/2];
    r = b[n/2 - 1] + b[n/2];
    
    ans = (r - l) + 1;
  } else {
    ans = b[n/2] - a[n/2] + 1;
  }
  
  cout << ans << endl;
}