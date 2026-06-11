#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n-1);
  rep(i,n){
    int x;
    cin >> x;
    x--;
    a[i] = x;
  }
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  
  ll ans=0;
  rep(i,n) ans+= b[a[i]];
  
  rep(i,n-1){
    if(a[i+1] == a[i]+1){
      ans += c[a[i]];
    }
  }
  
  cout << ans << endl;
  
  return(0);
}