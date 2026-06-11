#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
 ll n,a,b; cin >> n >> a >> b;
  
  ll mod = n / (a+b);
  ll count = (a+b) * mod;
  ll ans = a * mod;
 
  while(count < n) {
 	if(n-count > a) {
     ans += a;
    } else {
     ans += n-count;
     break;
    }
	count += a;
    
    if(n-count > b) {
      ans += b;
    } else {
      break;
    }
    count += b;
  }
  
  cout << ans << endl;
  
  return 0;
}
  