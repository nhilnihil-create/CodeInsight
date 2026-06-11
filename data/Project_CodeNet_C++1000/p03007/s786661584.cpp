#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  if(a[n-1] <= 0) {
    int ans = a[n-1];
    rep(i,n-1) ans -= a[i];
    cout << ans << endl;
    rep(i,n-1) {
      cout << a[n-1] << " " << a[i] << endl;
      a[n-1] -= a[i]; 
    }
  } else if(a[0] >= 0) {
    int ans = a[0];
    for(int i = 1; i < n-1; i++) ans -= a[i];
    ans = a[n-1] - ans;
    cout << ans << endl;
    for(int i = 1; i < n-1; i++) {
      cout << a[0] << " " << a[i] << endl;
      a[0] -= a[i];
    }
    cout << a[n-1] << " " << a[0] << endl;
  } else {
    int ans = 0;
    rep(i,n) ans += abs(a[i]);
    cout << ans << endl;
    int p = 0;
    while(a[p] < 0) {p++;}
    for(int i = p; i < n-1; i++) {
      cout << a[0] << " " << a[i] << endl;
      a[0] -= a[i];
    }
    rep(i,p) {
      cout << a[n-1] << " " << a[i] << endl;
      a[n-1] -= a[i];
    }
  }
  return 0;
}