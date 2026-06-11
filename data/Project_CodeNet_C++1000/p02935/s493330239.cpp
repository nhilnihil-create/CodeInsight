#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  sort(a.begin(),a.end());
  double ans=(a[0]+a[1])/2.0;
  
  rep(i,n-2){
    ans = (ans+a[i+2])/2.0;
  }
  
  cout << ans << endl;

  return(0);
}