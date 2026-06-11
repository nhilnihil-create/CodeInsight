#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
#include <math.h>
double log10(double x);
int main() {
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1LL;
 /* for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }*/
  for (int i = 0; i < n; i++) {
    //if (log10(a[i]) + log10(ans) > 18) {
    if (a[i] > 1000000000000000000LL / ans) {
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
  
  if (ans > 1000000000000000000LL /*|| ans < 0LL*/) {
    cout << -1 << endl;
  }
  else {
    cout << ans << endl;
  } 
  
} 
  

